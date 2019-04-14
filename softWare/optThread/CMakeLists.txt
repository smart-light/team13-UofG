cmake_minimum_required(VERSION 2.8.9)
set (CMAKE_CXX_STANDARD 11)
project (main)
add_executable(main MicroThread.cpp Micro.cpp )
find_package (Threads REQUIRED)


target_link_libraries (main ${CMAKE_THREAD_LIBS_INIT} wiringPi rt)

