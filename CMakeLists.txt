cmake_minimum_required(VERSION 3.26)
project(Briggs__Dieter__Tyler_Phase_Three)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Briggs__Dieter__Tyler_Phase_Three
        abstractSales.h
        customers.h
        main.cpp
        manager.h
        orders.h
        rainbow.h
        sales.h
        superSales.h
        supervisor.h
        transaction.h)
