#pragma once
#include "Convert.hpp"


inline bool icomp(const std::wstring& x, const std::wstring& y);
ttstr TVPSearchCD(const ttstr& name);

class StorageObject :
	public NativeObject
{
public:
	StorageObject();
};

/*		putFunc(L"", []TJSNATIVEARG{
			return TJS_S_OK;
			});*/