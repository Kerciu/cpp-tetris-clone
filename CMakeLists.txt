cmake_minimum_required(VERSION 3.10)

project(Tetris)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/src/gui)

include_directories(${PROJECT_SOURCE_DIR}/src/grid)

include_directories(${PROJECT_SOURCE_DIR}/src/main)

add_executable(tetris 
    src/main/main.cpp
    src/gui/TetrisGui.cpp
    src/gui/gradient.cpp
    src/gui/rounded_rectangle.cpp
    src/grid/Grid.cpp
    src/utils/Coords.cpp
    src/utils/colors.cpp
    src/blocks/Block.cpp
    src/blocks/Blocks.cpp
    src/game/game.cpp
    src/game/score.cpp
    src/process/process.cpp
    src/media/FontLoader.cpp
)

target_link_libraries(tetris sfml-graphics sfml-window sfml-system)

enable_testing()
