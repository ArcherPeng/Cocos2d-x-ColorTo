//
//  ColorToToLua.cpp
//  Game01
//
//  Created by ArcherPeng on 15/4/8.
//
//

#include "ColorToToLua.hpp"
#include "ColorTo.h"
#include "cocos2d.h"
#include "CCProtectedNode.h"
#include "CCAsyncTaskPool.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
int lua_ColorTo_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.ColorTo",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(tolua_S)-1;
    
    do
    {
        if (argc == 2)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.ColorTo:create");
            if (!ok) { break; }
            cocos2d::Color3B arg1;
            ok &= luaval_to_color3b(tolua_S, 3, &arg1, "cc.ColorTo:create");
            if (!ok) { break; }
            ColorTo* ret = ColorTo::create(arg0, arg1);
            object_to_luaval<ColorTo>(tolua_S, "cc.ColorTo",(ColorTo*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do
    {
        if (argc == 2)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.ColorTo:create");
            if (!ok) { break; }
            cocos2d::Color3B arg1;
            ok &= luaval_to_color3b(tolua_S, 3, &arg1, "cc.ColorTo:create");
            if (!ok) { break; }
            ColorTo* ret = ColorTo::create(arg0, arg1);
            object_to_luaval<ColorTo>(tolua_S, "cc.ColorTo",(ColorTo*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "cc.ColorTo:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_ColorTo_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_ColorTo_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ColorTo)");
    return 0;
}

int lua_register_ColorTo(lua_State* tolua_S)
{
    tolua_open(tolua_S);
    
    tolua_module(tolua_S,"cc",0);
    tolua_beginmodule(tolua_S,"cc");
    
    tolua_usertype(tolua_S,"cc.ColorTo");
    tolua_cclass(tolua_S,"ColorTo","cc.ColorTo","cc.ActionInterval",nullptr);
    
    tolua_beginmodule(tolua_S,"ColorTo");
    tolua_function(tolua_S,"create", lua_ColorTo_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ColorTo).name();
    g_luaType[typeName] = "cc.ColorTo";
    g_typeCast["ColorTo"] = "cc.ColorTo";
    
    tolua_endmodule(tolua_S);
    return 1;
}