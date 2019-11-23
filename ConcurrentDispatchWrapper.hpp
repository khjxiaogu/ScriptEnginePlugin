/*
 *  ConcurrentDispatchWrapper.hpp
 *  Provides TJS MultiThreading wrapping to avoid concurrent errors
 *
 *  Copyright (C) 2018-2019 khjxiaogu
 *
 *  Author: khjxiaogu
 *  Web: http: *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
*/
#pragma once
#include "propmacros.hpp"
#include <mutex>

#define LOCK std::unique_lock<std::mutex> lck(lock)

tjs_error PatchResult(tjs_error hr, tTJSVariant* result);
tjs_error PatchResult(tjs_error hr, iTJSDispatch2** result);
class concurrentiTJSDispatch2 : public iTJSDispatch2
{
	iTJSDispatch2* wrappedobj;
	std::mutex lock;
	inline iTJSDispatch2* TransferThis(iTJSDispatch2* objthis);
public:
	concurrentiTJSDispatch2(iTJSDispatch2* obj);
	virtual tjs_uint TJS_INTF_METHOD AddRef(void);
	virtual tjs_uint TJS_INTF_METHOD Release(void);
	virtual std::mutex* getLock() { return &lock; }
public:
	/*Locked function call,we wrap the result*/
	virtual tjs_error TJS_INTF_METHOD FuncCall(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, tTJSVariant* result, tjs_int numparams, tTJSVariant** param, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD FuncCallByNum(tjs_uint32 flag, tjs_int num, tTJSVariant* result, tjs_int numparams, tTJSVariant** param, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD PropGet(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, tTJSVariant* result, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD PropGetByNum(tjs_uint32 flag, tjs_int num, tTJSVariant* result, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD PropSet(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, const tTJSVariant* param, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD PropSetByNum(tjs_uint32 flag, tjs_int num, const tTJSVariant* param, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD GetCount(tjs_int* result, const tjs_char* membername, tjs_uint32* hint, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD GetCountByNum(tjs_int* result, tjs_int num, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD PropSetByVS(tjs_uint32 flag, tTJSVariantString* membername, const tTJSVariant* param, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD EnumMembers(tjs_uint32 flag, tTJSVariantClosure* callback, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD DeleteMember(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD DeleteMemberByNum(tjs_uint32 flag, tjs_int num, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD Invalidate(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD InvalidateByNum(tjs_uint32 flag, tjs_int num, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD IsValid(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD IsValidByNum(tjs_uint32 flag, tjs_int num, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD CreateNew(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, iTJSDispatch2** result, tjs_int numparams, tTJSVariant** param, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD CreateNewByNum(tjs_uint32 flag, tjs_int num, iTJSDispatch2** result, tjs_int numparams, tTJSVariant** param, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD Reserved1();
	virtual tjs_error TJS_INTF_METHOD IsInstanceOf(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, const tjs_char* classname, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD IsInstanceOfByNum(tjs_uint32 flag, tjs_int num, const tjs_char* classname, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD Operation(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, tTJSVariant* result, const tTJSVariant* param, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD OperationByNum(tjs_uint32 flag, tjs_int num, tTJSVariant* result, const tTJSVariant* param, iTJSDispatch2* objthis);
	virtual tjs_error TJS_INTF_METHOD NativeInstanceSupport(tjs_uint32 flag, tjs_int32 classid, iTJSNativeInstance** pointer);
	virtual tjs_error TJS_INTF_METHOD ClassInstanceInfo(tjs_uint32 flag, tjs_uint num, tTJSVariant* value);
	virtual tjs_error TJS_INTF_METHOD Reserved2();
	virtual tjs_error TJS_INTF_METHOD Reserved3();
};
