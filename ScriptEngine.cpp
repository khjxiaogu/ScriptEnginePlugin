
#include <string>
#include "tjs/tjs.h"

#include <windows.h>
#include "ncbind.hpp"
#include "ConcurrentDispatchWrapper.hpp"
#include "initscript.h"
#include "KRScript.h"
#include "KRunnable.h"
#include "debugItem.h"
#include "StorageObject.h"
#include "messages.h"
class TJSEngine {
	TJS::tTJS* engine;
	iTJSDispatch2* objthis;
	concurrentiTJSDispatch2* scGlobal;
	TJSEngine(iTJSDispatch2* objthis):objthis(objthis) {
		engine = new TJS::tTJS();
		engine->ExecScript(TJS::ttstr(TVPInitTJSScript));
		engine->SetPPValue(TJS_W("kirikiriz"), 1);
		scGlobal = new concurrentiTJSDispatch2((iTJSDispatch2*)engine->GetGlobal());
		DebugItem* di = new DebugItem(ttstr(L"KSE")+ttstr(int(objthis)));
		engine->SetConsoleOutput(di);
		PutToObject(L"Scripts",objthis, (iTJSDispatch2*)engine->GetGlobalNoAddRef());//put This as the scripts object in VM;
		PutToObject(L"Storages", new StorageObject(), (iTJSDispatch2*)engine->GetGlobalNoAddRef());//put A concurrent optimized Storage class in VM;
		PutToObject(L"Debug", new DebugObject(di), (iTJSDispatch2*)engine->GetGlobalNoAddRef());
	};

public:
	virtual ~TJSEngine() {
		delete scGlobal;
		engine->Shutdown();
		engine->Cleanup();
		engine->Release();

	}
	static tjs_error TJS_INTF_METHOD Factory(TJSEngine** inst, tjs_int n, tTJSVariant** p, iTJSDispatch2* objthis) {
		if (inst) {
			TJSEngine* self = *inst = new TJSEngine(objthis);
		}
		return TJS_S_OK;
	}
	void gc() {
		engine->DoGarbageCollection();
	}
	void garbageCollection() {
		engine->DoGarbageCollection();
	}
	static tjs_error TJS_INTF_METHOD setPreprocessor(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
		if (!self) return TJS_E_NATIVECLASSCRASH;
		if (n < 2) return TJS_E_BADPARAMCOUNT;
		self->engine->SetPPValue((const tjs_char *)(p[0]->AsStringNoAddRef()), p[1]->AsInteger());
		return TJS_S_OK;
	}
	static tjs_error TJS_INTF_METHOD getGlobal(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
		if (!self) return TJS_E_NATIVECLASSCRASH;
		*r=self->scGlobal;
		return TJS_S_OK;
	}
	static tjs_error TJS_INTF_METHOD dump(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
		if (!self) return TJS_E_NATIVECLASSCRASH;
		if (n < 1) return TJS_E_BADPARAMCOUNT;
		//lock the global dispatch to avoid accessing from main thread
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
	static tjs_error TJS_INTF_METHOD eval(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
		if (!self) return TJS_E_NATIVECLASSCRASH;
		if (n < 1) return TJS_E_BADPARAMCOUNT;
		//lock the global dispatch to avoid accessing from main thread
		//std::mutex*mtx= (self->scGlobal->getLock());
		//std::unique_lock<std::mutex> lock(*mtx);
		ttstr ex(*p[0]);
		TJS::ttstr exp(ex.c_str(),ex.length());
			if (n < 2)
				self->engine->EvalExpression(exp, (TJS::tTJSVariant*)r);
			else if (n < 3)
				self->engine->EvalExpression(exp, (TJS::tTJSVariant*)r, (TJS::iTJSDispatch2*)p[2]->AsObjectNoAddRef());
			else if (n < 4)
				self->engine->EvalExpression(exp, (TJS::tTJSVariant*)r, (TJS::iTJSDispatch2*)p[2]->AsObjectNoAddRef(),&(TJS::ttstr(*p[3])));
			else
				self->engine->EvalExpression(exp, (TJS::tTJSVariant*)r, (TJS::iTJSDispatch2*)p[2]->AsObjectNoAddRef(), &(TJS::ttstr(*p[3])),p[4]->AsInteger());
			return TJS_S_OK;
	}
	static tjs_error TJS_INTF_METHOD evalStorage(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
		if (!self) return TJS_E_NATIVECLASSCRASH;
		if (n < 1) return TJS_E_BADPARAMCOUNT;
		//lock the global dispatch to avoid accessing from main thread
		std::mutex* mtx = (self->scGlobal->getLock());
		//std::unique_lock<std::mutex> lock(*mtx);
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
					isbytecode = self->engine->LoadByteCode(stream,(TJS::tTJSVariant*)r, NULL, TVPExtractStorageName(name).c_str());
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
	static tjs_error TJS_INTF_METHOD exec(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
		if (!self) return TJS_E_NATIVECLASSCRASH;
		if (n < 1) return TJS_E_BADPARAMCOUNT;
		//lock the global dispatch to avoid accessing from main thread
		//std::mutex* mtx = (self->scGlobal->getLock());
		//std::unique_lock<std::mutex> lock(*mtx);
		ttstr ex(*p[0]);
		TJS::ttstr exp(ex.c_str(), ex.length());
		if (n < 2)
			self->engine->ExecScript(exp);
		else if (n < 3)
			self->engine->ExecScript(exp,NULL, (TJS::iTJSDispatch2*)p[1]->AsObjectNoAddRef());
		else if (n < 4)
			self->engine->ExecScript(exp, NULL, (TJS::iTJSDispatch2*)p[1]->AsObjectNoAddRef(),&(TJS::ttstr(*p[2])));
		else
			self->engine->ExecScript(exp, NULL, (TJS::iTJSDispatch2*)p[1]->AsObjectNoAddRef(), &(TJS::ttstr(*p[2])),p[3]->AsInteger());
		return TJS_S_OK;
	}
	static tjs_error TJS_INTF_METHOD execAsync(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
		if (!self) return TJS_E_NATIVECLASSCRASH;
		if (n < 1) return TJS_E_BADPARAMCOUNT;
		//preprocess running task
		std::mutex* mtx = (self->scGlobal->getLock());
		ttstr ex(*p[0]);
		TJS::iTJSDispatch2* cxt=NULL;
		tjs_int line=NULL;
		TJS::ttstr * name=NULL;
		TJS::ttstr* exp = new TJS::ttstr(ex.c_str(), ex.length());
		if (n > 1)
			cxt = (TJS::iTJSDispatch2*)p[1]->AsObjectNoAddRef();
		if (n > 2)
			name = new TJS::ttstr(*p[2]);
		if (n > 3)
			line = p[3]->AsInteger();

		(new KRunnable([=] {
			//lock the global dispatch to avoid accessing from main thread
			//RUN_MAIN(TVPAddLog(L"Ready To Run"););
			std::unique_lock<std::mutex> mx(*mtx);
			try {
				self->engine->ExecScript(*exp, NULL, cxt, name, line);
			}
			catch(TJS::eTJSError err){
				//std::wstring msg;
				//msg.assign(err.GetMessageW().AsStdString());
				//(new KRunnable([=] {TVPAddLog(msg.c_str()); }))->runTask();
			}
			delete exp;
			delete name;
			//RUN_MAIN(TVPAddLog(L"Run finished"););
			}))->runTaskAsync();
			return TJS_S_OK;
	}
	static tjs_error TJS_INTF_METHOD execStorage(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
		if (!self) return TJS_E_NATIVECLASSCRASH;
		if (n < 1) return TJS_E_BADPARAMCOUNT;
		//lock the global dispatch to avoid accessing from main thread
		//std::mutex* mtx = (self->scGlobal->getLock());
		//std::unique_lock<std::mutex> lock(*mtx);
		// execute storage which contains script
		ttstr name = *p[0];

		ttstr modestr;
		if (n > 1)
			modestr = ttstr(p[1]);
		{ // for bytecode
			TJS::tTJSBinaryStream* stream = TVPCreateBinaryStreamForRead(*(TJS::ttstr*)&name, *(TJS::ttstr*) & modestr);
			if (stream) {
				bool isbytecode = false;
				try {
					isbytecode = self->engine->LoadByteCode(stream,NULL,NULL, TVPExtractStorageName(name).c_str());
				}
				catch (...) {
					delete stream;
					return TJS_E_INVALIDPARAM;
				}
				delete stream;
				if (isbytecode) return TJS_S_OK;
			}
		}
		iTJSTextReadStream* stream = TVPCreateTextStreamForRead(name,modestr);
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
		
		self->engine->ExecScript(buffer.c_str(),NULL,NULL, TVPExtractStorageName(name).c_str());
		return TJS_S_OK;
	}
	static tjs_error TJS_INTF_METHOD execStorageAsync(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
		if (!self) return TJS_E_NATIVECLASSCRASH;
		if (n < 1) return TJS_E_BADPARAMCOUNT;
		//preprocess running task
		std::mutex* mtx = (self->scGlobal->getLock());

		TJS::ttstr * name =new TJS::ttstr(*p[0]);
		TJS::ttstr * modestr;
		if (n > 1)
			modestr = new TJS::ttstr(*p[1]);
		(new KRunnable([=] {
			//lock the global dispatch to avoid accessing from main thread
			std::unique_lock<std::mutex> mx(*mtx);
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
			self->engine->ExecScript(buffer.c_str(), NULL, NULL, TVPExtractStorageName(*(ttstr*)name).c_str());
			return TJS_S_OK;
			}))->runTaskAsync();
		return TJS_S_OK;
	}

	void close() {
	}
};
//NCB_POST_REGIST_CALLBACK(initEngine);
NCB_REGISTER_CLASS(TJSEngine) {
	CONSTRUCTOR;
	NCB_METHOD(gc);
	NCB_METHOD(garbageCollection);
	FUNCTION(setPreprocessor);
	FUNCTION(getGlobal);
	FUNCTION(dump);
	FUNCTION(eval);
	FUNCTION(evalStorage);
	FUNCTION(exec);
	FUNCTION(execAsync);
	FUNCTION(execStorage);
	FUNCTION(execStorageAsync);
}
inline void TVPLoadMessage() {
	TJS::TVPLoadMessage();
}
inline void TVPFreeMessages() {
	TJS::TVPFreeMessages();
}
NCB_POST_REGIST_CALLBACK(TVPLoadMessage);
NCB_POST_UNREGIST_CALLBACK(TVPFreeMessages);