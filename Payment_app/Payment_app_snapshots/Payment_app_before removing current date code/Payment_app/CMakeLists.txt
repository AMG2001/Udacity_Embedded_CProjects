cmake_minimum_required(VERSION 3.24)
project(Payment_app)

set(CMAKE_CXX_STANDARD 14)

include_directories(Card)
include_directories(Server)
include_directories(Terminal)

add_executable(Payment_app
        Card/card.c
        Card/card.h
        Server/server.c
        Server/server.h
        Terminal/terminal.c
        Terminal/terminal.h
        Payment_app.cpp)
