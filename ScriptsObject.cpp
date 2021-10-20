#include "ScriptsObject.h"

ScriptsObject::ScriptsObject(TJSEngine* belong) :belong(belong)
{
	putFunc(L"eval", [this]TJSNATIVEARG{
		return TJSEngine::eval(r,n,p,this->belong);
		});
	putFunc(L"exec", [this]TJSNATIVEARG{
		return TJSEngine::exec(r,n,p,this->belong);
		});
	putFunc(L"evalStorage", [this]TJSNATIVEARG{
		return TJSEngine::evalStorage(r,n,p,this->belong);
		});
	putFunc(L"execStorage", [this]TJSNATIVEARG{
		return TJSEngine::execStorage(r,n,p,this->belong);
	});
	putFunc(L"callEvent", [this]TJSNATIVEARG{
		TVPPostEvent(this->belong->getObject(),this->belong->getObject(),ttstr(L"onEvent"),NULL,NULL,n,*p);
		return TJS_S_OK;
		});
}
