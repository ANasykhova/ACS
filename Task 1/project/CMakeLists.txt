# set minimum cmake version
cmake_minimum_required(VERSION 3.5)

# project name and language
project(task1)

set(CMAKE_CXX_STANDART 11)
set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
    # Headers
    rnd.h
    triangle.h
    rectangle.h
    circle.h
    shape.h
    container.h

    # Sources
    triangle.cpp
    rectangle.cpp
    circle.cpp
    shape.cpp
    container.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${CPPS})
