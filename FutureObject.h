#pragma once
#include "Convert.hpp"
#include "KRunnable.h"
class FutureObject :
	public NativeObject,public KFuture
{
	virtual void BeforeDestruction(void) {
	}
public:
	tTJSVariant result;
	FutureObject() {
		putFunc(L"wait", [this]TJSNATIVEARG{
				if (n > 0)
					*r = wait(p[0]->AsInteger());
				else
					wait();
		return TJS_S_OK;
			});
		putFunc(L"isCompleted", [this]TJSNATIVEARG{
				*r = isCompleted();
		return TJS_S_OK;
			});
		putFunc(L"onComplete", []TJSNATIVEARG{ return TJS_S_OK; });
		putFunc(L"onFail", []TJSNATIVEARG{ return TJS_S_OK; });
		putProp<tTJSVariant>(L"result", [this](){return result; });
	}
	virtual void start() {
		AddRef();
		__super::start();
	}
	virtual void fail() {
		__super::fail();
		//TVPAddLog(ttstr((int)GetRefCount()).c_str());
		//(new KRunnable([this] {/*TVPPostEvent(this, this, ttstr(L"onComplete"), NULL, NULL, 0,0); */this->FuncCall(0, L"onComplete", 0, NULL, 0, NULL, this); }))->runTask();
		//auto par = new tTJSVariant[0];
		TVPPostEvent(this, this, ttstr(L"onFail"), NULL, NULL, 0, 0);
		//TVPAddLog(ttstr((int)GetRefCount()).c_str());
		Release();
		//delete[] par;
	}
	virtual void complete() {
		__super::complete();
		//TVPAddLog(ttstr((int)GetRefCount()).c_str());
		//(new KRunnable([this] {/*TVPPostEvent(this, this, ttstr(L"onComplete"), NULL, NULL, 0,0); */this->FuncCall(0, L"onComplete", 0, NULL, 0, NULL, this); }))->runTask();
		//auto par = new tTJSVariant[0];
		TVPPostEvent(this,this,ttstr(L"onComplete"),NULL,NULL,1,&result);
		//TVPAddLog(ttstr((int)GetRefCount()).c_str());
		Release();
		//delete[] par;
	}

};

