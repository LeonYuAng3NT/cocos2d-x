/****************************************************************************
Copyright (c) 2013 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "cocostudio/CCComAttribute.h"
using namespace cocos2d;

namespace cocostudio {

ComAttribute::ComAttribute(void)
: _dict(NULL)
{
    _name = "ComAttribute";
}

ComAttribute::~ComAttribute(void)
{
    _dict.clear();
}

bool ComAttribute::init()
{
    return true;
}

void ComAttribute::setInt(const std::string& key, int value)
{
    _dict.insert(key, __Integer::create(value));
}

void ComAttribute::setFloat(const std::string& key, float value)
{
    _dict.insert(key, __Float::create(value));
}

void ComAttribute::setBool(const std::string& key, bool value)
{
    _dict.insert(key, __Bool::create(value));
}

void ComAttribute::setCString(const std::string& key, const std::string& value)
{
    _dict.insert(key, __String::create(value));
}

int ComAttribute::getInt(const std::string& key, int def) const
{
    Object *ret = _dict.at(key);
	if(ret)
    {
		
		if(__Integer *obj=dynamic_cast<__Integer*>(ret) )
			return obj->getValue();
	}
    return def;
}

float ComAttribute::getFloat(const std::string& key, float def) const
{
    Object *ret =  _dict.at(key);
    if(ret)
    {
		
		if( __Float *obj=dynamic_cast<__Float*>(ret) )
			return obj->getValue();
	}
    return def;
}

bool ComAttribute::getBool(const std::string& key, bool def) const
{
    Object *ret =  _dict.at(key);
	if(ret) {
		
		if(__Bool *obj = dynamic_cast<__Bool*>(ret) )
			return obj->getValue();
	}
    return def;
}

std::string ComAttribute::getCString(const std::string& key, const std::string& def) const
{
   Object *ret =  _dict.at(key);
	if(ret) {
		
		if( __String *obj = dynamic_cast<__String*>(ret) )
			return obj->getCString();
	}
    return def;
}

ComAttribute* ComAttribute::create(void)
{
	ComAttribute * pRet = new ComAttribute();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}


}
