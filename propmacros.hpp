/*
 *  propmacros.h
 *
 *  Define macros for setting or getting TJS property or object
 *  Copyright (C) 2018-2019 khjxiaogu
 *
 *  Author: khjxiaogu
 *  Web: http://www.khjxiaogu.com
*/
#pragma once
#include <windows.h>
#include "tp_stub.h"

#ifndef MACROS
#define MACROS
#define GETSTR(a) tTJSVariant(a).GetString()
#define CONSTRUCTOR Factory(&Class::Factory)
#define NATIVECLASS(a) NCB_REGISTER_CLASS(a)
#define FUNCTION(a) RawCallback(#a, &Class::##a, 0)
template<class T>
T* alloc(int count = 1);
//put object to object
 void PutToObject(const wchar_t* name, iTJSDispatch2* data, iTJSDispatch2* inst);
//put object to object by num
 void PutToObject(int name, iTJSDispatch2* data, iTJSDispatch2* inst);
 template<class T>
 void PutToObject(int name, T data, iTJSDispatch2* inst) {
	 tTJSVariant i(data);
	 inst->PropSetByNum(
		 TJS_MEMBERENSURE,
		 (tjs_int)name,
		 &i,
		 inst
	 );
 }
 template<class T>
 void PutToObject(const wchar_t* name, T data, iTJSDispatch2* inst) {
	 tTJSVariant i(data);
	 inst->PropSet(
		 TJS_MEMBERENSURE,
		 name,
		 NULL,
		 &i,
		 inst
	 );
 }
tTJSVariant getMember(iTJSDispatch2* dic, const tjs_char* key);
tTJSVariant getMember(iTJSDispatch2* dic, tjs_int key);
#endif
