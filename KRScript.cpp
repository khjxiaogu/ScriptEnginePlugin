#include "KRScript.h"
#include "tjs/tjsRandomGenerator.h"


TJS::tTJSBinaryStream* TVPCreateBinaryStreamForRead(const TJS::tTJSString& name,
	const TJS::tTJSString& modestr) {
	IStream* stream = TVPCreateIStream(ttstr(name.c_str()), TJS_BS_READ);

	const tjs_char* o_ofs = TJS_strchr(modestr.c_str(), TJS_W('o'));
	if (o_ofs != NULL) {
		// seek to offset
		o_ofs++;
		tjs_char buf[256];
		int i;
		for (i = 0; i < 255; i++) {
			if (o_ofs[i] >= TJS_W('0') && o_ofs[i] <= TJS_W('9'))
				buf[i] = o_ofs[i];
			else break;
		}
		buf[i] = 0;
		tjs_uint64 ofs = ttstr(buf).AsInteger();
		ULARGE_INTEGER cur;
		stream->Seek(*((LARGE_INTEGER*)&ofs), SEEK_SET, &cur);
	}
	return (TJS::tTJSBinaryStream*)TVPCreateBinaryStreamAdapter(stream);
}
TJS::tTJSBinaryStream* TVPCreateBinaryStreamForWrite(const TJS::tTJSString& name,
	const TJS::tTJSString& modestr) {
	IStream* stream = TVPCreateIStream(ttstr(name.c_str()), TJS_BS_WRITE);

	const tjs_char* o_ofs = TJS_strchr(modestr.c_str(), TJS_W('o'));
	if (o_ofs != NULL) {
		// seek to offset
		o_ofs++;
		tjs_char buf[256];
		int i;
		for (i = 0; i < 255; i++) {
			if (o_ofs[i] >= TJS_W('0') && o_ofs[i] <= TJS_W('9'))
				buf[i] = o_ofs[i];
			else break;
		}
		buf[i] = 0;
		tjs_uint64 ofs = ttstr(buf).AsInteger();
		ULARGE_INTEGER cur;
		stream->Seek(*((LARGE_INTEGER*)&ofs), SEEK_SET, &cur);
	}
	return (TJS::tTJSBinaryStream*)TVPCreateBinaryStreamAdapter(stream);
}
void initEngine() {

	tTJSVariant val;
	// Set eval expression mode
	if (TVPGetCommandLine(TJS_W("-evalcontext"), &val))
	{
		ttstr str(val);
		if (str == TJS_W("global"))
		{
			TJS::TJSEvalOperatorIsOnGlobal = true;
			TJS::TJSWarnOnNonGlobalEvalOperator = true;
		}
	}

	// Set igonre-prop compat mode
	if (TVPGetCommandLine(TJS_W("-unaryaster"), &val))
	{
		ttstr str(val);
		if (str == TJS_W("compat"))
		{
			TJS::TJSUnaryAsteriskIgnoresPropAccess = true;
		}
	}

	// Set debug mode
	if (TVPGetCommandLine(TJS_W("-debug"), &val))
	{
		ttstr str(val);
		if (str == TJS_W("yes"))
		{
			TJS::TJSEnableDebugMode = true;
			//			if(TVPGetCommandLine(TJS_W("-warnrundelobj"), &val) )
			//			{
			//				str = val;
			//				if(str == TJS_W("yes"))
			//				{
			TJS::TJSWarnOnExecutionOnDeletingObject = true;
			//				}
			//			}
		}
	}

	// add kirikiriz
	

	// set TJSGetRandomBits128
	TJS::TJSGetRandomBits128 = TVPGetRandomBits128;
	// script system initialization
	
	
	// set console output gateway handler
	//TVPScriptEngine->SetConsoleOutput(TVPGetTJS2ConsoleOutputGateway());
	
	// set text stream functions
	TJS::TJSCreateTextStreamForRead =(TJS::iTJSTextReadStream * (*)(const TJS::tTJSString &,const TJS::tTJSString&)) TVPCreateTextStreamForRead;
	TJS::TJSCreateTextStreamForWrite = (TJS::iTJSTextWriteStream * (*)(const TJS::tTJSString&, const TJS::tTJSString&)) TVPCreateTextStreamForWrite;
	
	// set binary stream functions
	TJS::TJSCreateBinaryStreamForRead = TVPCreateBinaryStreamForRead;
	TJS::TJSCreateBinaryStreamForWrite = TVPCreateBinaryStreamForWrite;


}