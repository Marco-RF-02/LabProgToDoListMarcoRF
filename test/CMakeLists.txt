cmake_minimum_required(VERSION 3.20)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp FileControllerTest.cpp TodoItemTest.cpp FileControllerFixture.cpp DateTest.cpp TodolistTest.cpp TodolistFixture.cpp)

add_executable(runTodoTests ${TEST_SOURCE_FILES})
target_link_libraries(runTodoTests gtest gtest_main core)