cmake_minimum_required(VERSION 3.20)

project(taskan)

add_executable(taskman 
	src/main.c
	src/task.c
	src/input.c
	src/filelog.c
)

target_include_directories(taskman PRIVATE
	include 
)
