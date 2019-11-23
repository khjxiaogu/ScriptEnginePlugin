#include "StorageObject.h"
#include "KRunnable.h"
struct equal_wchar_ignorecase {
	bool operator()(wchar_t x, wchar_t y) const {
		return std::tolower(x) == std::tolower(y);
	}
};
bool icomp(const std::wstring& x, const std::wstring& y) {
	return x.size() == y.size() && std::equal(x.begin(), x.end(), y.begin(), equal_wchar_ignorecase());
}

ttstr TVPSearchCD(const ttstr& name)
{
	// search CD which has specified volume label name.
	// return drive letter ( such as 'A' or 'B' )
	// return empty string if not found.
	std::wstring narrow_name = name.c_str();

	wchar_t dr[4];
	for (dr[0] = L'A', dr[1] = L':', dr[2] = L'\\', dr[3] = 0; dr[0] <= L'Z'; dr[0]++)
	{
		if (::GetDriveType(dr) == DRIVE_CDROM)
		{
			wchar_t vlabel[256];
			wchar_t fs[256];
			DWORD mcl = 0, sfs = 0;
			GetVolumeInformation(dr, vlabel, 255, NULL, &mcl, &sfs, fs, 255);
			if (icomp(std::wstring(vlabel), narrow_name))
				//if(std::string(vlabel).AnsiCompareIC(narrow_name)==0)
				return ttstr((tjs_char)dr[0]);
		}
	}
	return ttstr();
}

StorageObject::StorageObject() {
	// put concurrent objects
	putFunc(L"addAutoPath", []TJSNATIVEARG{
		if (n < 1)
		return TJS_E_BADPARAMCOUNT;
		ttstr stor;
	stor = p[0]->AsStringNoAddRef();
	stor.Independ();
	(new KRunnable([stor] {TVPAddAutoPath(stor); }))->runTask();
	return TJS_S_OK;
		});
	putFunc(L"removeAutoPath", []TJSNATIVEARG{
				if (n < 1)
		return TJS_E_BADPARAMCOUNT;
		ttstr stor;
	stor = p[0]->AsStringNoAddRef();
	stor.Independ();
	(new KRunnable([stor] {TVPRemoveAutoPath(stor); }))->runTask();
	return TJS_S_OK;
		});
	//put async objects
	putFunc(L"chopStorageExt", []TJSNATIVEARG{
				if (n < 1)
		return TJS_E_BADPARAMCOUNT;
		// chop storage's extension and return it.
		ttstr name = p[0]->AsStringNoAddRef();
	const tjs_char* s = name.c_str();
	tjs_int slen = name.GetLen();
	const tjs_char* pc = s + slen;
	pc--;
	while (pc >= s)
	{
		if (*pc == TJS_W('\\')) break;
		if (*pc == TJS_W('/')) break;
		if (*pc == TJS_W('>')) break;
		if (*pc == TJS_W('.'))
		{
			// found extension delimiter
			*r = ttstr(s, (int)(pc - s));
			return TJS_S_OK;
		}

		pc--;
	}

	// not found
	*r = name;
	return TJS_S_OK;
		});
	putFunc(L"extractStorageExt", []TJSNATIVEARG{
		// extract an extension from name.
		// returned string will contain extension delimiter ( '.' ), except for
		// missing extension of the input string.
		// ( returns null string when input string does not have an extension )
		ttstr name = p[0]->AsStringNoAddRef();
		const tjs_char * s = name.c_str();
		tjs_int slen = name.GetLen();
		const tjs_char * px = s + slen;
		px--;
		while (px >= s)
		{
			if (*px == TJS_W('\\')) break;
			if (*px == TJS_W('/')) break;
			if (*px == '>') break;
			if (*px == TJS_W('.'))
			{
				// found extension delimiter
				tjs_int extlen = (tjs_int)(slen - (px - s));
				*r = ttstr(px, extlen);
			}

			px--;
		}

		// not found
		*r = ttstr();
		return TJS_S_OK;
		});
	putFunc(L"extractStoragePath", []TJSNATIVEARG{
				if (n < 1)
		return TJS_E_BADPARAMCOUNT;
		// extract "name"'s path ( including last delimiter ) and return it.
		ttstr name = p[0]->AsStringNoAddRef();
	const tjs_char* s = name.c_str();
	tjs_int slen = name.GetLen();
	const tjs_char* pc = s + slen;
	pc--;
	while (pc >= s)
	{
		if (*pc == TJS_W('\\')) break;
		if (*pc == TJS_W('/')) break;
		if (*pc == L'>') break;

		pc--;
	}

	pc++;
	*r = ttstr(s, (int)(pc - s));
	return TJS_S_OK;
		});
	putFunc(L"extractStorageName", []TJSNATIVEARG{
				if (n < 1)
		return TJS_E_BADPARAMCOUNT;
		// extract "name"'s storage name ( excluding path ) and return it.
		ttstr name = p[0]->AsStringNoAddRef();
	const tjs_char* s = name.c_str();
	tjs_int slen = name.GetLen();
	const tjs_char* pc = s + slen;
	pc--;
	while (pc >= s)
	{
		if (*pc == TJS_W('\\')) break;
		if (*pc == TJS_W('/')) break;
		if (*pc == L'>') break;

		pc--;
	}

	pc++;
	if (pc == s)
		*r = name;
	else
		*r = ttstr(pc, (int)(slen - (pc - s)));
	return TJS_S_OK;
		});
	putFunc(L"getFullPath", []TJSNATIVEARG{
				if (n < 1)
		return TJS_E_BADPARAMCOUNT;
		// extract "name"'s path ( including last delimiter ) and return it.
		ttstr name = p[0]->AsStringNoAddRef();
	auto ro = new KRunnable([&] {name = TVPNormalizeStorageName(name); }, new KFuture());
	ro->runTask();
	ro->getFuture()->wait();
	*r = name;
	return TJS_S_OK;
		});
	putFunc(L"getLocalName", []TJSNATIVEARG{
				if (n < 1)
		return TJS_E_BADPARAMCOUNT;
		// extract "name"'s path ( including last delimiter ) and return it.
		ttstr name = p[0]->AsStringNoAddRef();
	auto ro = new KRunnable([&] {TVPGetLocalName(name); }, new KFuture());
	ro->runTask();
	ro->getFuture()->wait();
	*r = name;
	return TJS_S_OK;
		});
	putFunc(L"getPlacedPath", []TJSNATIVEARG{
				if (n < 1)
		return TJS_E_BADPARAMCOUNT;
		// extract "name"'s path ( including last delimiter ) and return it.
		ttstr name = p[0]->AsStringNoAddRef();
	auto ro = new KRunnable([&] {*r = name = TVPGetPlacedPath(name); }, new KFuture());
	ro->runTask();
	ro->getFuture()->wait();
	return TJS_S_OK;
		});
	putFunc(L"isExistentStorage", []TJSNATIVEARG{
				if (n < 1)
		return TJS_E_BADPARAMCOUNT;
		// extract "name"'s path ( including last delimiter ) and return it.
		ttstr name = p[0]->AsStringNoAddRef();
	auto ro = new KRunnable([&] {*r = TVPIsExistentStorage(name); }, new KFuture());
	ro->runTask();
	ro->getFuture()->wait();
	return TJS_S_OK;
		});
	putFunc(L"searchCD", []TJSNATIVEARG{
				if (n < 1)
		return TJS_E_BADPARAMCOUNT;
		// extract "name"'s path ( including last delimiter ) and return it.
		ttstr name = p[0]->AsStringNoAddRef();
	*r = TVPSearchCD(name);
	return TJS_S_OK;
		});
	putFunc(L"selectFile", []TJSNATIVEARG{
		return E_NOTIMPL;
		});
}
