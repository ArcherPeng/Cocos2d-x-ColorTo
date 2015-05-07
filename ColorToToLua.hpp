//
//  ColorToToLua.h
//  Game01
//
//  Created by ArcherPeng on 15/4/8.
//
//



#include "base/ccConfig.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

#ifndef __Game01__ColorToToLua__
#define __Game01__ColorToToLua__
int lua_register_ColorTo(lua_State* tolua_S);

#endif /* defined(__Game01__ColorToToLua__) */
