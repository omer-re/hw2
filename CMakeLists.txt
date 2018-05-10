cmake_minimum_required(VERSION 3.10)
project(hw2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(hw2
        defs.h
        main.c
        SocialNetwork.c
        SocialNetwork.h
        User.c
        User.h)
