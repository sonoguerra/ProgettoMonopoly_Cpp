cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(ProgettoFinale)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_RELEASE "-O2")

include_directories(include)

add_library(monopoly
	include/board.h
	include/humanPlayer.h
	include/player.h
	include/robotPlayer.h
	include/square.h
	include/game.h
	src/board.cpp
	src/humanPlayer.cpp
	src/player.cpp
	src/robotPlayer.cpp
	src/square.cpp
	src/game.cpp
)

add_executable(main
	src/main.cpp
)

target_link_libraries(main
	monopoly
)