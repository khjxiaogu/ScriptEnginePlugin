#pragma once
#include <string>

#include "tjs/tjs.h"

#include "windows.h"
#include "ncbind.hpp"

#include "TJSToStubWrapper.hpp"
void initEngine();
TJS::tTJSBinaryStream* TVPCreateBinaryStreamForRead(const TJS::tTJSString& name,
	const TJS::tTJSString& modestr);
TJS::tTJSBinaryStream* TVPCreateBinaryStreamForWrite(const TJS::tTJSString& name,
	const TJS::tTJSString& modestr);