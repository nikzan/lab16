cmake_minimum_required(VERSION 3.30)
project(lab16)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab16 main.cpp
        Node.cpp
        Node.h
        CircularList.cpp
        CircularList.h
        DoubleLinkedList.cpp
        DoubleLinkedList.h
        CircularDoubleList.cpp
        CircularDoubleList.h
        ChildrenCircle.cpp
        ChildrenCircle.h)
