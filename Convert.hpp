#pragma once
/*
 *  Convert.hpp
 *  Provides Simple Convertion Template between C++ types and TJS types
 *
 *  Copyright (C) 2018-2019 khjxiaogu
 *
 *  Author: khjxiaogu
 *  Web: http://www.khjxiaogu.com
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
*/

#include <functional>
#include <fstream>
#include <vector>
#include <windows.h>
#include "propmacros.hpp"
#include "ncbind.hpp"
#include <string>
#include "CPConv.h"
#include "Callers.hpp"
#include "NativeObject.hpp"

//Convert T(JS) String to std C(++) UTF-8 String. 
std::string TStrToCStrUTF8(const ttstr& str);
//Convert T(JS) String to std C(++) ANSI String. 
std::string TStrToCStr(const ttstr& str);
//Get T(JS) String from std C(++) String. 
ttstr CStrToTStr(const std::string& str);
//Convert T(JS) Octet to std C(++) String. 
std::string TOctToCStr(tTJSVariantOctet* oct);
//Get T(JS) Octet from std C(++) String. 
tTJSVariantOctet* CStrToTOct(std::string s);
//Iterate Object members and call function.
void IterateObject(iTJSDispatch2* obj, std::function<void(tTJSVariant*, tTJSVariant*)>func);
