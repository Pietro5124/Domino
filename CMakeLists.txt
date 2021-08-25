cmake_minimum_required(VERSION 3.20)
project(Domino)

set(CMAKE_C_STANDARD 11)

include_directories(PUCRAFT)

add_executable(Domino
        PUCRAFT/Dom_PUCRAFT_View.c
        PUCRAFT/Dom_PUCRAFT_View.h
        PUCRAFT/Dom_PUCRAFT_Model.c
        PUCRAFT/Dom_PUCRAFT_Model.h
        PUCRAFT/Dom_PUCRAFT_Controller.c
        PUCRAFT/Dom_PUCRAFT_Controller.h
        PUCRAFT/Dom_PUCRAFT.c
        )