cmake_minimum_required(VERSION 3.10)

project(TetrisTests)

add_subdirectory(googletest)

find_package(GTest REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/../src)

add_executable(runTests 
    test_tetris.cpp
)

target_link_libraries(runTests GTest::GTest GTest::Main sfml-graphics sfml-window sfml-system)
