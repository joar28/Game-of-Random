//
// Created by joar on 11/11/16.
//

#ifndef GAME_OF_RANDOM_LUA_H
#define GAME_OF_RANDOM_LUA_H

#include <lua5.3/lua.h>

void print_error(lua_State* state);

// usage: execute("lua/callback.lua");
void execute(const char* filename);
void print_error(lua_State* state);
int howdy(lua_State* state);


#endif //GAME_OF_RANDOM_LUA_H
