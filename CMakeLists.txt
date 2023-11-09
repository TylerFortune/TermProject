cmake_minimum_required(VERSION 3.26)
project(Test_Term_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Test_Term_Project main.cpp
        customers.h
        orders.h
        rainbow.h
        transaction.h
        salesperson.h
        abstractsales.h
        superSales.h
        manager.h
        supervisor.h
)
