#pragma once
#include "Convert.hpp"
#include "ScriptEngine.h"

class ScriptsObject :
	public NativeObject
{
	TJSEngine* belong;
public:
	ScriptsObject(TJSEngine* belong);
};