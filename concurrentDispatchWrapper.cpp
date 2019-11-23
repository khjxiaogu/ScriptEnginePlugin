#include "concurrentDispatchWrapper.hpp"
//we don't need this because this is causing problems
tjs_error PatchResult(tjs_error hr, iTJSDispatch2** result) {
	/*if (hr == TJS_S_OK && result != NULL) {
		iTJSDispatch2* obj = *result;
		if (getMember(obj, L"isConcurrent").AsInteger() != 1)
			*result = (iTJSDispatch2*)new concurrentiTJSDispatch2(obj);
	}*/
	return hr;
}
tjs_error PatchResult(tjs_error hr, tTJSVariant* result) {
	/*if (hr == TJS_S_OK && result != NULL && result->Type() == tvtObject) {
		iTJSDispatch2* obj = result->AsObject();
		if (getMember(obj, L"isConcurrent").AsInteger() != 1)
			*result = (iTJSDispatch2*)new concurrentiTJSDispatch2(obj);
	}*/
	return hr;
}


inline iTJSDispatch2* concurrentiTJSDispatch2::TransferThis(iTJSDispatch2* objthis)
{
	return objthis==this?wrappedobj:objthis;
}

concurrentiTJSDispatch2::concurrentiTJSDispatch2(iTJSDispatch2* obj) :wrappedobj(obj) {}

tjs_uint TJS_INTF_METHOD concurrentiTJSDispatch2::AddRef(void) {
	LOCK;
	return wrappedobj->AddRef();
}

tjs_uint TJS_INTF_METHOD concurrentiTJSDispatch2::Release(void) {
	LOCK;
	return wrappedobj->Release();
}

/*Locked function call,we wrap the result*/

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::FuncCall(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, tTJSVariant* result, tjs_int numparams, tTJSVariant** param, iTJSDispatch2* objthis) {
	LOCK;
	return PatchResult(wrappedobj->FuncCall(flag, membername, hint, result, numparams, param, TransferThis(objthis)), result);
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::FuncCallByNum(tjs_uint32 flag, tjs_int num, tTJSVariant* result, tjs_int numparams, tTJSVariant** param, iTJSDispatch2* objthis) {
	LOCK;
	return PatchResult(wrappedobj->FuncCallByNum(flag, num, result, numparams, param, TransferThis(objthis)), result);
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::PropGet(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, tTJSVariant* result, iTJSDispatch2* objthis) {
	LOCK;
	if(membername)
	if (!wcscmp(membername, L"isConcurrent")) {
		*result = 1;
		return TJS_S_OK;
	}

	return PatchResult(wrappedobj->PropGet(flag, membername, hint, result, TransferThis(objthis)), result);
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::PropGetByNum(tjs_uint32 flag, tjs_int num, tTJSVariant* result, iTJSDispatch2* objthis) {
	LOCK;
	return PatchResult(wrappedobj->PropGetByNum(flag, num, result, TransferThis(objthis)), result);
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::PropSet(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, const tTJSVariant* param, iTJSDispatch2* objthis) {
	LOCK;
	return wrappedobj->PropSet(flag, membername, hint, param, TransferThis(objthis));
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::PropSetByNum(tjs_uint32 flag, tjs_int num, const tTJSVariant* param, iTJSDispatch2* objthis) {
	LOCK;
	return wrappedobj->PropSetByNum(flag, num, param, TransferThis(objthis));
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::GetCount(tjs_int* result, const tjs_char* membername, tjs_uint32* hint, iTJSDispatch2* objthis) {
	LOCK;
	return wrappedobj->GetCount(result, membername, hint, TransferThis(objthis));
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::GetCountByNum(tjs_int* result, tjs_int num, iTJSDispatch2* objthis) {
	LOCK;
	return wrappedobj->GetCountByNum(result, num, TransferThis(objthis));
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::PropSetByVS(tjs_uint32 flag, tTJSVariantString* membername, const tTJSVariant* param, iTJSDispatch2* objthis) {
	LOCK;
	return wrappedobj->PropSetByVS(flag, membername, param, TransferThis(objthis));
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::EnumMembers(tjs_uint32 flag, tTJSVariantClosure* callback, iTJSDispatch2* objthis) {
	LOCK;
	return wrappedobj->EnumMembers(flag, callback, TransferThis(objthis));
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::DeleteMember(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, iTJSDispatch2* objthis) {
	LOCK;
	return wrappedobj->DeleteMember(flag, membername, hint, TransferThis(objthis));
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::DeleteMemberByNum(tjs_uint32 flag, tjs_int num, iTJSDispatch2* objthis) {
	LOCK;
	return wrappedobj->DeleteMemberByNum(flag, num, TransferThis(objthis));
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::Invalidate(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, iTJSDispatch2* objthis) {
	LOCK;
	return wrappedobj->Invalidate(flag, membername, hint, TransferThis(objthis));
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::InvalidateByNum(tjs_uint32 flag, tjs_int num, iTJSDispatch2* objthis) {
	LOCK;
	return wrappedobj->InvalidateByNum(flag, num, TransferThis(objthis));
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::IsValid(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, iTJSDispatch2* objthis) {
	LOCK;
	return wrappedobj->IsValid(flag, membername, hint, TransferThis(objthis));
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::IsValidByNum(tjs_uint32 flag, tjs_int num, iTJSDispatch2* objthis) {
	LOCK;
	return wrappedobj->IsValidByNum(flag, num, TransferThis(objthis));
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::CreateNew(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, iTJSDispatch2** result, tjs_int numparams, tTJSVariant** param, iTJSDispatch2* objthis) {
	LOCK;
	return PatchResult(wrappedobj->CreateNew(flag, membername, hint, result, numparams, param, TransferThis(objthis)), result);
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::CreateNewByNum(tjs_uint32 flag, tjs_int num, iTJSDispatch2** result, tjs_int numparams, tTJSVariant** param, iTJSDispatch2* objthis) {
	LOCK;
	return PatchResult(wrappedobj->CreateNewByNum(flag, num, result, numparams, param, TransferThis(objthis)), result);
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::Reserved1() {
	return TJS_E_NOTIMPL;

}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::IsInstanceOf(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, const tjs_char* classname, iTJSDispatch2* objthis) {
	LOCK;
	return wrappedobj->IsInstanceOf(flag, membername, hint, classname, TransferThis(objthis));
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::IsInstanceOfByNum(tjs_uint32 flag, tjs_int num, const tjs_char* classname, iTJSDispatch2* objthis) {
	LOCK;
	return wrappedobj->IsInstanceOfByNum(flag, num, classname, TransferThis(objthis));
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::Operation(tjs_uint32 flag, const tjs_char* membername, tjs_uint32* hint, tTJSVariant* result, const tTJSVariant* param, iTJSDispatch2* objthis) {
	LOCK;
	return PatchResult(wrappedobj->Operation(flag, membername, hint, result, param, TransferThis(objthis)), result);
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::OperationByNum(tjs_uint32 flag, tjs_int num, tTJSVariant* result, const tTJSVariant* param, iTJSDispatch2* objthis) {
	LOCK;
	return PatchResult(wrappedobj->OperationByNum(flag, num, result, param, TransferThis(objthis)), result);
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::NativeInstanceSupport(tjs_uint32 flag, tjs_int32 classid, iTJSNativeInstance** pointer) {
	LOCK;
	return wrappedobj->NativeInstanceSupport(flag, classid, pointer);
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::ClassInstanceInfo(tjs_uint32 flag, tjs_uint num, tTJSVariant* value) {
	LOCK;
	return wrappedobj->ClassInstanceInfo(flag, num, value);
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::Reserved2() {
	return TJS_E_NOTIMPL;
}

tjs_error TJS_INTF_METHOD concurrentiTJSDispatch2::Reserved3() {
	return TJS_E_NOTIMPL;
}
