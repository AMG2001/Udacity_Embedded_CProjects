cmake_minimum_required(VERSION 3.24)
project(payment_app C)

set(CMAKE_C_STANDARD 23)

add_executable(payment_app main.c Terminal/terminal.c Card/card.c)
