#include "Convert.hpp"

//Convert T(JS) String to std C(++) UTF-8 String. 
std::string TStrToCStrUTF8(const ttstr& str) {
	char* cs = WCSToUTF8(str.c_str());
	std::string cstr;
	cstr.assign(cs);
	delete[] cs;
	return cstr;
}

//Convert T(JS) String to std C(++) ANSI String. 
std::string TStrToCStr(const ttstr& str) {
	char* cs = UnicodeToAnsi(str.c_str());
	std::string cstr;
	cstr.assign(cs);
	delete[] cs;
	return cstr;
}

//Get T(JS) String from std C(++) String. 
ttstr CStrToTStr(const std::string& str) {
	tTJSString res((const tjs_nchar*)str.c_str());
	return res;
}

//Convert T(JS) Octet to std C(++) String. 
std::string TOctToCStr(tTJSVariantOctet* oct) {
	return std::string((const char*)oct->GetData(), oct->GetLength());
}

//Get T(JS) Octet from std C(++) String. 
tTJSVariantOctet* CStrToTOct(std::string s) {
	return new tTJSVariantOctet((unsigned char*)s.c_str(), s.size());
}

//Iterate Object members and call function.
void IterateObject(iTJSDispatch2* obj, std::function<void(tTJSVariant*, tTJSVariant*)> func) {
	ObjectIterateCaller* caller = new ObjectIterateCaller(func);
	tTJSVariantClosure tvc(caller);
	obj->EnumMembers(NULL, &tvc, NULL);
	caller->Release();
}
