cmake_minimum_required(VERSION 2.6)
project(Task)

# Source files list
set(SOURCE_FILES
        # Headers
        rnd.h
        Circle.h
        Shape.h
        Triangle.h
        Rectangle.h
        Container.h

        # Sources
        Circle.cpp
        Shape.cpp
        Triangle.cpp
        Rectangle.cpp
        Container.cpp
        main.cpp
)

add_executable(Task ${SOURCE_FILES})
