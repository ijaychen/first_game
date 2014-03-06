/*************************************************************************
	> File Name: lua_configure.cpp
	> Author: cjj
	> Created Time: Wed 05 Mar 2014 11:22:08 AM CST
 ************************************************************************/

#include "lua_configure.h"

extern "C"
{
#include "lua_h/lua.h"
#include "lua_h/lualib.h"
#include "lua_h/lauxlib.h"
}

namespace base{

LuaConfigure::LuaConfigure()
{
	m_pLuaState = NULL;	
}

LuaCOnfigure::~LuaConfigure()
{
	if(m_pLuaState)
	{
		lua_close(m_pLuaState);
	}

}

static LuaConfigure * LuaConfigure::GetInstance()
{
	static LuaConfigure _instance;
	return &_instance;
}

bool LuaConfigure::Initialize()
{
	m_pLuaState = luaL_newState();
	if(!m_pLuaState)
	{
		//log
		return false;
	}
	luaL_openlibs(m_pLuaState);
	return true;
}

}
