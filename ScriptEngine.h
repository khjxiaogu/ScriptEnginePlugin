#pragma once
#include "ncbind.hpp"
#include "ConcurrentDispatchWrapper.hpp"
#include "tjs/tjs.h"
class TJSEngine {
	TJS::tTJS* engine;
	iTJSDispatch2* objthis;
	concurrentiTJSDispatch2* scGlobal;
	TJSEngine(iTJSDispatch2* objthis);;

public:
	virtual ~TJSEngine();
	static tjs_error TJS_INTF_METHOD Factory(TJSEngine** inst, tjs_int n, tTJSVariant** p, iTJSDispatch2* objthis);
	void gc();
	void garbageCollection();
	iTJSDispatch2* getObject() {
		return objthis;
	}
	static tjs_error TJS_INTF_METHOD setPreprocessor(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self);
	static tjs_error TJS_INTF_METHOD getGlobal(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self);
	static tjs_error TJS_INTF_METHOD dump(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self);
	/*static tjs_error TJS_INTF_METHOD dump(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self) {
		if (!self) return TJS_E_NATIVECLASSCRASH;
		if (n < 1) return TJS_E_BADPARAMCOUNT;
		//lock the global dispatch to avoid accessing from main thread
		self->engine->SetConsoleOutput()
		return TJS_S_OK;
	}*/
	static tjs_error TJS_INTF_METHOD eval(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self);
	static tjs_error TJS_INTF_METHOD evalAsync(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self);
	static tjs_error TJS_INTF_METHOD evalStorage(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self);
	static tjs_error TJS_INTF_METHOD exec(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self);
	static tjs_error TJS_INTF_METHOD execAsync(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self);
	static tjs_error TJS_INTF_METHOD execStorage(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self);
	static tjs_error TJS_INTF_METHOD execStorageAsync(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self);
	static tjs_error TJS_INTF_METHOD createInstanceAsync(tTJSVariant* r, tjs_int n, tTJSVariant** p, TJSEngine* self);
	void close();
};