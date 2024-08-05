cmake_minimum_required(VERSION 3.12)

project(Tetris)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/src/gui)
include_directories(${PROJECT_SOURCE_DIR}/src/grid)
include_directories(${PROJECT_SOURCE_DIR}/src/main)
include_directories(${PROJECT_SOURCE_DIR}/src/utils)
include_directories(${PROJECT_SOURCE_DIR}/src/blocks)
include_directories(${PROJECT_SOURCE_DIR}/src/game)
include_directories(${PROJECT_SOURCE_DIR}/src/process)
include_directories(${PROJECT_SOURCE_DIR}/src/media)

set(SOURCES
    src/main/main.cpp
    src/gui/TetrisGui.cpp
    src/gui/gradient.cpp
    src/gui/rounded_rectangle.cpp
    src/gui/arrow.cpp
    src/grid/Grid.cpp
    src/utils/Coords.cpp
    src/utils/colors.cpp
    src/utils/exceptions.cpp
    src/blocks/Block.cpp
    src/blocks/Blocks.cpp
    src/game/game.cpp
    src/game/score.cpp
    src/process/process.cpp
    src/media/FontLoader.cpp
    src/media/AudioPlayer.cpp
)

add_executable(tetris ${SOURCES})
target_link_libraries(tetris sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

enable_testing()

add_subdirectory(tests/googletest)
include_directories(tests/googletest/googletest/include)

set(TEST_SOURCES
    tests/test_tetris.cpp
    src/gui/TetrisGui.cpp
    src/gui/gradient.cpp
    src/gui/rounded_rectangle.cpp
    src/gui/arrow.cpp
    src/grid/Grid.cpp
    src/utils/Coords.cpp
    src/utils/colors.cpp
    src/utils/exceptions.cpp
    src/blocks/Block.cpp
    src/blocks/Blocks.cpp
    src/game/game.cpp
    src/game/score.cpp
    src/process/process.cpp
    src/media/FontLoader.cpp
    src/media/AudioPlayer.cpp
)

add_executable(RunTests ${TEST_SOURCES})
target_link_libraries(RunTests gtest gtest_main sfml-system sfml-window sfml-graphics sfml-network sfml-audio)


include(GoogleTest)
gtest_discover_tests(RunTests)

add_test(NAME RunTests COMMAND RunTests)
