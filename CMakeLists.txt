cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(progettoFinale)

include_directories(include)

add_executable(main
	src/main.cpp
)
add_library(Square
	include/square.h
	src/square.cpp
)
add_library(Player
	include/player.h
	src/player.cpp
)

add_library(HumanPlayer
	include/humanPlayer.h
	src/humanPlayer.cpp
)

add_library(RobotPlayer
	include/robotPlayer.h
	src/robotPlayer.cpp
)

add_library(ExchangeMoney
	include/exchangeMoney.h
	src/exchangeMoney.cpp
)


target_link_libraries(main
	ExchangeMoney
	Square
	Player
	HumanPlayer
	RobotPlayer
)

target_link_libraries(HumanPlayer
	Player
)

target_link_libraries(RobotPlayer
	Player
)
