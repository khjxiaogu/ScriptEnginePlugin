#include "DebugItem.h"

DebugItem::DebugItem(const ttstr& name) :itemname(name + L":") {
	//nmsgs.resize(20);
#ifdef THROW_GLOBAL_EXCEPTION
	exeptmsgs.resize(20);
#endif
	erritemname = L"[Error]" + itemname;
	kr = new KRunnable([this] {depletmsgs(); });
	kr->is_timer = true;
}

DebugItem::~DebugItem()
{
	delete kr;
}

void DebugItem::ExceptionPrint(const tjs_char* msg) {
	if (!msg)
		return;
	std::lock_guard<std::mutex> lck(lock);
#ifdef THROW_GLOBAL_EXCEPTION
	exeptmsgs.push_back(erritemname + msg);
#else
	nmsgs.push_back(erritemname + msg);
#endif
	kr->runTask();
}

void DebugItem::Print(const tjs_char* msg) {
	if (!msg)
		return;
	std::lock_guard<std::mutex> lck(lock);
	nmsgs.push_back(itemname + msg);
	kr->runTask();
}

void DebugItem::depletmsgs() {
	
	
	ttstr msg;
	//msg.AppendBuffer(10);
#ifdef THROW_GLOBAL_EXCEPTION
	while (!exeptmsgs.empty()) {
		msg = exeptmsgs.front();
		exeptmsgs.pop_front();
		TVPThrowExceptionMessage(msg);
	}
#endif
	std::lock_guard<std::mutex> lck(lock);
	while (!nmsgs.empty()) {
		msg = nmsgs.front();
		nmsgs.pop_front();
		TVPAddLog(msg);
	}
};

DebugObject::DebugObject(DebugItem* di) :item(di) {
	putFunc(L"message", [this]TJSNATIVEARG{
		for (int i = 0; i < n; i++)
		item->Print(ttstr(*p[i]).c_str());
	return TJS_S_OK;
		});
	putFunc(L"notice", [this]TJSNATIVEARG{
		item->Print((const tjs_char*)(p[0]->AsStringNoAddRef()));
	return TJS_S_OK;
		});
	putFunc(L"getLastLog", [this]TJSNATIVEARG{
		TJS::iTJSDispatch2 * array = TJS::TJSCreateArrayObject();
	std::lock_guard<std::mutex> lck(item->lock);
	ttstr msg;
	tjs_int i = 0;
	while (!item->nmsgs.empty()) {
		msg = item->nmsgs.front();
		item->nmsgs.pop_front();
		PutToObject(i++, msg, (iTJSDispatch2*)array);
	}
	*r = tTJSVariant((iTJSDispatch2*)array, (iTJSDispatch2*)array);
	return TJS_S_OK;
		});
	putFunc(L"startLogToFile", []TJSNATIVEARG{
		return TJS_E_NOTIMPL;
		});
	putFunc(L"logAsError", []TJSNATIVEARG{
		return TJS_S_OK;
		});
}
