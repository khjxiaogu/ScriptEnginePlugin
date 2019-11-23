#include "propmacros.hpp"
template<class T>
T* alloc(int count) {
	return (T*)malloc(sizeof(T) * count);
}
//put object to object
void PutToObject(const wchar_t* name, iTJSDispatch2* data, iTJSDispatch2* inst) {
	tTJSVariant i(data);
	inst->PropSet(
		TJS_MEMBERENSURE,
		name,
		NULL,
		&i,
		inst
	);
	data->Release();
}

//put object to object by num
void PutToObject(int name, iTJSDispatch2* data, iTJSDispatch2* inst) {
	tTJSVariant i(data);
	inst->PropSetByNum(
		TJS_MEMBERENSURE,
		(tjs_int)name,
		&i,
		inst
	);
	data->Release();
}

tTJSVariant getMember(iTJSDispatch2* dic, const tjs_char* key) {
	tTJSVariant r;
	dic->PropGet(TJS_MEMBERENSURE, key, NULL, &r, dic);
	return r;
}

tTJSVariant getMember(iTJSDispatch2* dic, tjs_int key) {
	tTJSVariant r;
	dic->PropGetByNum(TJS_MEMBERENSURE, key, &r, dic);
	return r;
}

