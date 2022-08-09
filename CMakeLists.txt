cmake_minimum_required(VERSION 3.20)
project(LabProgToDoListMarcoRF)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES TodoItem.cpp TodoItem.h FileController.cpp FileController.h Date.cpp Date.h)
add_executable(LabProgToDoListMarcoRF main.cpp )
add_library(core ${SOURCE_FILES})
target_link_libraries(LabProgToDoListMarcoRF core)
