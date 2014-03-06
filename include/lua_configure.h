/*************************************************************************
	> File Name: lua_configure.h
	> Author: cjj
	> Created Time: Wed 05 Mar 2014 11:18:23 AM CST
 ************************************************************************/

#ifndef LUA_CONFIGURE_H
#define LUA_CONFIGURE_H
namespace base{

class LuaConfigure
{
public:
	virtual ~LuaConfigure();
	static LuaConfigure * GetInstance();
	bool Initialize();
private:
	LuaConfigure();
	lua_State * m_pLuaState;

}

}
#endif
