cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(ProgettoFinale)

include_directories(include)

add_library(monopoly
	include/board.h
	include/exchangeMoney.h
	include/game.h
	include/humanPlayer.h
	include/player.h
	include/robotPlayer.h
	include/square.h
	src/board.cpp
	src/exchangeMoney.cpp
	src/game.cpp
	src/humanPlayer.cpp
	src/player.cpp
	src/robotPlayer.cpp
	src/square.cpp
)

add_executable(main
	src/main.cpp
)

target_link_libraries(main
	monopoly
)