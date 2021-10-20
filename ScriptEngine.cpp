
#include <string>
#include "tjs/tjs.h"
#include "ScriptEngine.h"
#include <windows.h>
#include "initscript.h"
#include "KRScript.h"
#include "KRunnable.h"
#include "debugItem.h"
#include "StorageObject.h"
#include "ScriptsObject.h"
#include "messages.h"
#include "FutureObject.h"
#define CREATE_FUTURE FutureObject* fo=NULL;\
if (r)\
fo = new FutureObject();
#define END_FUTURE if (r) {\
*r = tTJSVariant(fo, fo);\
fo->Release();\
			}

//NCB_POST_REGIST_CALLBACK(initEngine);
NCB_REGISTER_CLASS(TJSEngine) {
	CONSTRUCTOR;
	NCB_METHOD(gc);
	NCB_METHOD(garbageCollection);
	FUNCTION(setPreprocessor);
	FUNCTION(getGlobal);
	FUNCTION(dump);
	FUNCTION(eval);
	FUNCTION(evalAsync);
	FUNCTION(evalStorage);
	FUNCTION(exec);
	FUNCTION(execAsync);
	FUNCTION(execStorage);
	FUNCTION(execStorageAsync);
	FUNCTION(createInstanceAsync);
}
inline void TVPLoadMessage() {
	createMessageWindow();
	TJS::TVPLoadMessage();
}
inline void TVPFreeMessages() {
	TJS::TVPFreeMessages();
}
NCB_POST_REGIST_CALLBACK(TVPLoadMessage);
NCB_POST_UNREGIST_CALLBACK(TVPFreeMessages);

inline TJSEngine::TJSEngine(iTJSDispatch2* objthis) :objthis(objthis) {
	engine = new TJS::tTJS();
	engine->ExecScript(TJS::ttstr(TVPInitTJSScript));
	engine->SetPPValue(TJS_W("kirikiriz"), 1);
	scGlobal = new concurrentiTJSDispatch2((iTJSDispatch2*)engine->GetGlobalNoAddRef());
	DebugItem* di = new DebugItem(ttstr(L"Thread") + ttstr(int(objthis)));
	engine->SetConsoleOutput(di);
	PutToObject(L"Scripts",new ScriptsObject(this), (iTJSDispatch2*)engine->GetGlobalNoAddRef());//put This as the scripts object in VM;
	PutToObject(L"Storages", new StorageObject(), (iTJSDispatch2*)engine->GetGlobalNoAddRef());//put A concurrent optimized Storage class in VM;
	PutToObject(L"Debug", new DebugObject(di), (iTJSDispatch2*)engine->GetGlobalNoAddRef());
}

inline TJSEngine::~TJSEngine() {
	delete scGlobal;
	engine->Shutdown();
	engine->Cleanup();
	engine->Release();

}

inline tjs_error TJS_INTF_METHOD TJSEngine::Factory(TJSEngine** inst, tjs_int n, tTJSVariant** p, iTJSDispatch2* objthis) {
	if (inst) {
		TJSEngine* self = *inst = new TJSEngine(objthis);
	}
	return TJS_S_OK;
}

inline void TJSEngine::gc() {
	engine->DoGarbageCollection();
}

inline void TJSEngine::garbageCollection() {
	engine->DoGarbageCollection();
}

inline tjs_error TJS_INTF_METHOD TJSEngine::setPreprocessor(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
	if (!self) return TJS_E_NATIVECLASSCRASH;
	if (n < 2) return TJS_E_BADPARAMCOUNT;
	self->engine->SetPPValue((const tjs_char*)(p[0]->AsStringNoAddRef()), p[1]->AsInteger());
	return TJS_S_OK;
}

inline tjs_error TJS_INTF_METHOD TJSEngine::getGlobal(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
	if (!self) return TJS_E_NATIVECLASSCRASH;
	*r = self->scGlobal;
	return TJS_S_OK;
}

inline tjs_error TJS_INTF_METHOD TJSEngine::dump(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
	if (!self) return TJS_E_NATIVECLASSCRASH;
	if (n < 1) return TJS_E_BADPARAMCOUNT;
	self->engine->Dump();
	return TJS_S_OK;
}

/*static tjs_error TJS_INTF_METHOD dump(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
if (!self) return TJS_E_NATIVECLASSCRASH;
if (n < 1) return TJS_E_BADPARAMCOUNT;
//lock the global dispatch to avoid accessing from main thread
self->engine->SetConsoleOutput()
return TJS_S_OK;
}*/

inline tjs_error TJS_INTF_METHOD TJSEngine::eval(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
	if (!self) return TJS_E_NATIVECLASSCRASH;
	if (n < 1) return TJS_E_BADPARAMCOUNT;
	//lock the global dispatch to avoid accessing from main thread
	//std::mutex*mtx= (self->scGlobal->getLock());
	//std::lock_guard<std::mutex> lock(*mtx);
	ttstr ex(*p[0]);
	TJS::ttstr exp(ex.c_str(), ex.length());
	if (n < 2)
		self->engine->EvalExpression(exp, (TJS::tTJSVariant*)r);
	else if (n < 3)
		self->engine->EvalExpression(exp, (TJS::tTJSVariant*)r, (TJS::iTJSDispatch2*)p[2]->AsObjectNoAddRef());
	else if (n < 4)
		self->engine->EvalExpression(exp, (TJS::tTJSVariant*)r, (TJS::iTJSDispatch2*)p[2]->AsObjectNoAddRef(), &(TJS::ttstr(*p[3])));
	else
		self->engine->EvalExpression(exp, (TJS::tTJSVariant*)r, (TJS::iTJSDispatch2*)p[2]->AsObjectNoAddRef(), &(TJS::ttstr(*p[3])), p[4]->AsInteger());
	return TJS_S_OK;
}

inline tjs_error TJS_INTF_METHOD TJSEngine::evalAsync(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
	if (!self) return TJS_E_NATIVECLASSCRASH;
	if (n < 1) return TJS_E_BADPARAMCOUNT;
	//preprocess running task
	std::mutex* mtx = (self->scGlobal->getLock());
	ttstr ex(*p[0]);
	TJS::iTJSDispatch2* cxt = NULL;
	tjs_int line = NULL;
	TJS::ttstr* name = NULL;
	TJS::ttstr* exp = new TJS::ttstr(ex.c_str(), ex.length());
	if (n > 1)
		cxt = (TJS::iTJSDispatch2*)p[1]->AsObject();
	if (n > 2)
		name = new TJS::ttstr(*p[2]);
	if (n > 3)
		line = p[3]->AsInteger();
	CREATE_FUTURE;
	(new KRunnable([=] {
		//lock the global dispatch to avoid accessing from main thread
		std::lock_guard<std::mutex> mx(*mtx);
		try {
			if (fo)
				self->engine->EvalExpression(*exp, (TJS::tTJSVariant*) & (fo->result), cxt, name, line);
			else
				self->engine->EvalExpression(*exp, NULL, cxt, name, line);
		}
		catch (...) {
		}
		try {
			cxt->Release();
			delete exp;
			delete name;
		}
		catch (...) {}
		}, fo))->runTaskAsync();
		END_FUTURE
			return TJS_S_OK;
}

inline tjs_error TJS_INTF_METHOD TJSEngine::evalStorage(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
	if (!self) return TJS_E_NATIVECLASSCRASH;
	if (n < 1) return TJS_E_BADPARAMCOUNT;
	//lock the global dispatch to avoid accessing from main thread
	std::mutex* mtx = (self->scGlobal->getLock());
	//std::lock_guard<std::mutex> lock(*mtx);
	// execute storage which contains script
	ttstr name = *p[0];

	ttstr modestr;
	if (n > 1)
		modestr = ttstr(p[1]);
	{ // for bytecode
		TJS::tTJSBinaryStream* stream = TVPCreateBinaryStreamForRead(*(TJS::ttstr*) & name, *(TJS::ttstr*) & modestr);
		if (stream) {
			bool isbytecode = false;
			try {
				isbytecode = self->engine->LoadByteCode(stream, (TJS::tTJSVariant*)r, NULL, TVPExtractStorageName(name).c_str());
			}
			catch (...) {
				delete stream;
				return TJS_E_INVALIDPARAM;
			}
			delete stream;
			if (isbytecode) return TJS_S_OK;
		}
	}
	iTJSTextReadStream* stream = TVPCreateTextStreamForRead(name, modestr);
	ttstr buffer;
	try
	{
		stream->Read(buffer, 0);
	}
	catch (...)
	{
		stream->Destruct();
		throw;
	}
	stream->Destruct();
	self->engine->ExecScript(buffer.c_str(), (TJS::tTJSVariant*)r, NULL, TVPExtractStorageName(name).c_str());
	return TJS_S_OK;
}

inline tjs_error TJS_INTF_METHOD TJSEngine::exec(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
	if (!self) return TJS_E_NATIVECLASSCRASH;
	if (n < 1) return TJS_E_BADPARAMCOUNT;
	//lock the global dispatch to avoid accessing from main thread
	//std::mutex* mtx = (self->scGlobal->getLock());
	//std::lock_guard<std::mutex> lock(*mtx);
	ttstr ex(*p[0]);
	TJS::ttstr exp(ex.c_str(), ex.length());
	if (n < 2)
		self->engine->ExecScript(exp);
	else if (n < 3)
		self->engine->ExecScript(exp, NULL, (TJS::iTJSDispatch2*)p[1]->AsObjectNoAddRef());
	else if (n < 4)
		self->engine->ExecScript(exp, NULL, (TJS::iTJSDispatch2*)p[1]->AsObjectNoAddRef(), &(TJS::ttstr(*p[2])));
	else
		self->engine->ExecScript(exp, NULL, (TJS::iTJSDispatch2*)p[1]->AsObjectNoAddRef(), &(TJS::ttstr(*p[2])), p[3]->AsInteger());
	return TJS_S_OK;
}

inline tjs_error TJS_INTF_METHOD TJSEngine::execAsync(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
	if (!self) return TJS_E_NATIVECLASSCRASH;
	if (n < 1) return TJS_E_BADPARAMCOUNT;
	//preprocess running task
	std::mutex* mtx = (self->scGlobal->getLock());
	ttstr ex(*p[0]);
	TJS::iTJSDispatch2* cxt = NULL;
	tjs_int line = NULL;
	TJS::ttstr* name = NULL;
	TJS::ttstr* exp = new TJS::ttstr(ex.c_str(), ex.length());
	if (n > 1)
		cxt = (TJS::iTJSDispatch2*)p[1]->AsObject();
	if (n > 2)
		name = new TJS::ttstr(*p[2]);
	if (n > 3)
		line = p[3]->AsInteger();
	CREATE_FUTURE;
	(new KRunnable([=] {
		//lock the global dispatch to avoid accessing from main thread
		std::lock_guard<std::mutex> mx(*mtx);
		try {
			if (fo)
				self->engine->ExecScript(*exp, (TJS::tTJSVariant*) & (fo->result), cxt, name, line);
			else
				self->engine->ExecScript(*exp, NULL, cxt, name, line);
		}
		catch (...) {
		}
		try {
			cxt->Release();
			delete exp;
			delete name;
		}
		catch (...) {}
		}, fo))->runTaskAsync();
		END_FUTURE
			return TJS_S_OK;
}

inline tjs_error TJS_INTF_METHOD TJSEngine::execStorage(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
	if (!self) return TJS_E_NATIVECLASSCRASH;
	if (n < 1) return TJS_E_BADPARAMCOUNT;
	//lock the global dispatch to avoid accessing from main thread
	//std::mutex* mtx = (self->scGlobal->getLock());
	//std::lock_guard<std::mutex> lock(*mtx);
	// execute storage which contains script
	ttstr name = *p[0];

	ttstr modestr;
	if (n > 1)
		modestr = ttstr(p[1]);
	{ // for bytecode
		TJS::tTJSBinaryStream* stream = TVPCreateBinaryStreamForRead(*(TJS::ttstr*) & name, *(TJS::ttstr*) & modestr);
		if (stream) {
			bool isbytecode = false;
			try {
				isbytecode = self->engine->LoadByteCode(stream, NULL, NULL, TVPExtractStorageName(name).c_str());
			}
			catch (...) {
				delete stream;
				return TJS_E_INVALIDPARAM;
			}
			delete stream;
			if (isbytecode) return TJS_S_OK;
		}
	}
	iTJSTextReadStream* stream = TVPCreateTextStreamForRead(name, modestr);
	ttstr buffer;
	try
	{
		stream->Read(buffer, 0);
	}
	catch (...)
	{
		stream->Destruct();
		throw;
	}
	stream->Destruct();

	self->engine->ExecScript(buffer.c_str(), NULL, NULL, TVPExtractStorageName(name).c_str());
	return TJS_S_OK;
}

inline tjs_error TJS_INTF_METHOD TJSEngine::execStorageAsync(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
	if (!self) return TJS_E_NATIVECLASSCRASH;
	if (n < 1) return TJS_E_BADPARAMCOUNT;
	//preprocess running task
	std::mutex* mtx = (self->scGlobal->getLock());

	TJS::ttstr* name = new TJS::ttstr(*p[0]);
	TJS::ttstr* modestr;
	if (n > 1)
		modestr = new TJS::ttstr(*p[1]);
	CREATE_FUTURE;
	(new KRunnable([=] {
		//lock the global dispatch to avoid accessing from main thread
		std::lock_guard<std::mutex> mx(*mtx);
		// execute storage which contains script
		{ // for bytecode
			TJS::tTJSBinaryStream* stream = TVPCreateBinaryStreamForRead(*name, *modestr);
			if (stream) {
				bool isbytecode = false;
				try {
					isbytecode = self->engine->LoadByteCode(stream, NULL, NULL, TVPExtractStorageName(*(ttstr*)name).c_str());
				}
				catch (...) {
					delete stream;
					return TJS_E_INVALIDPARAM;
				}
				delete stream;
				if (isbytecode) return TJS_S_OK;
			}
		}
		iTJSTextReadStream* stream = TVPCreateTextStreamForRead(*(ttstr*)name, *(ttstr*)modestr);
		ttstr buffer;
		try
		{
			stream->Read(buffer, 0);
		}
		catch (...)
		{
			stream->Destruct();
			throw;
		}
		stream->Destruct();
		if (fo)
			self->engine->ExecScript(buffer.c_str(), (TJS::tTJSVariant*) & (fo->result), NULL, TVPExtractStorageName(*(ttstr*)name).c_str());
		else
			self->engine->ExecScript(buffer.c_str(), NULL, NULL, TVPExtractStorageName(*(ttstr*)name).c_str());
		return TJS_S_OK;
		}, fo))->runTaskAsync();
		END_FUTURE;
		return TJS_S_OK;
}

inline tjs_error TJS_INTF_METHOD TJSEngine::createInstanceAsync(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
	if (!self) return TJS_E_NATIVECLASSCRASH;
	if (n < 1) return TJS_E_BADPARAMCOUNT;
	//preprocess running task
	std::mutex* mtx = (self->scGlobal->getLock());
	auto obj = p[0]->AsObjectClosure();
	tTJSVariant** params;
	if (n > 1) {
		params = new tTJSVariant * [n - 1];
		for (int i = 1; i < n; i++)
			params[i - 1] = new tTJSVariant(*p[i]);
	}
	CREATE_FUTURE;
	(new KRunnable([=] {
		//lock the global dispatch to avoid accessing from main thread
		std::lock_guard<std::mutex> mx(*mtx);
		// execute storage which contains script
		iTJSDispatch2* obr;
		tjs_error te = obj.CreateNew(0, NULL, NULL, &obr, n - 1, params, obj.ObjThis);
		if (te != TJS_S_OK)
			self->engine->OutputToConsole((ttstr(L"error code: ") + ttstr(te)).c_str());
		if (fo)
			fo->result = tTJSVariant(obr, obr);
		obr->Release();
		for (int i = 1; i < n; i++)
			delete params[i];
		delete[] params;
		}, fo))->runTaskAsync();
		END_FUTURE;
		return TJS_S_OK;
}

inline void TJSEngine::close() {
}
