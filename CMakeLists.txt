cmake_minimum_required(VERSION 3.20)
project(Domino)

set(CMAKE_C_STANDARD 11)

include_directories(Domino_PUCRAFT)

add_executable(Domino
        Domino_PUCRAFT/dominoController.c
        Domino_PUCRAFT/dominoController.h
        Domino_PUCRAFT/dominoModel.c
        Domino_PUCRAFT/dominoModel.h
        Domino_PUCRAFT/dominoView.c
        Domino_PUCRAFT/dominoView.h
        Domino_PUCRAFT/Domino.c)