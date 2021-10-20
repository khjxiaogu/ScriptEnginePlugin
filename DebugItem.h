#pragma once
#include <string>

#include <windows.h>
#include "tp_stub.h"

#include "Convert.hpp"
#include "tjs/tjs.h"
#include "tjs/tjsArray.h"
#include <deque>
#include "KRunnable.h"
class DebugItem :public TJS::iTJSConsoleOutput
{
	ttstr itemname;
	ttstr erritemname;
	std::deque<ttstr> nmsgs;
	std::deque<ttstr> exeptmsgs;
	std::mutex lock;
	KRunnable* kr;
public:
	DebugItem(const ttstr& name);
	virtual ~DebugItem();
	virtual void ExceptionPrint(const tjs_char* msg);
	virtual void Print(const tjs_char* msg);
	void depletmsgs();
	friend class DebugObject;
};
class DebugObject :public NativeObject {
	DebugItem* item;
public:
	DebugObject(DebugItem* di);

};
