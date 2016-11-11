cmake_minimum_required(VERSION 3.5)
project(game_of_random)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic")

set(SOURCE_FILES
        main.cpp
        globals.h

        Game.cpp Game.h

        ResourceLoader.cpp ResourceLoader.h

        states/StateInterface.cpp states/StateInterface.h
        states/StateInitLoad.cpp states/StateInitLoad.h
        states/StateMainMenu.cpp states/StateMainMenu.h
        states/StateGame.cpp states/StateGame.h

        objects/ObjectInterface.cpp objects/ObjectInterface.h objects/ObjectParticleBall.cpp objects/ObjectParticleBall.h VectorMath.cpp VectorMath.h lua.cpp lua.h)


add_executable(game_of_random ${SOURCE_FILES})

target_link_libraries (game_of_random
        #jsoncpp
        lua5.3
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio)