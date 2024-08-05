cmake_minimum_required(VERSION 3.12)

project(Tetris)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

add_executable(tetris
    src/main/main.cpp
    src/gui/TetrisGui.cpp
    src/gui/gui_components/GradientCreator.cpp
    src/gui/gui_components/RoundedRectangleDrawer.cpp
    src/gui/gui_components/Arrow.cpp
    src/grid/Grid.cpp
    src/utils/Coords.cpp
    src/utils/ColorCreator.cpp
    src/utils/exceptions.cpp
    src/blocks/Block.cpp
    src/blocks/Blocks.cpp
    src/game/Game.cpp
    src/game/Score.cpp
    src/process/Process.cpp
    src/media/FontLoader.cpp
    src/media/AudioPlayer.cpp
)

target_link_libraries(tetris
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
)

target_include_directories(tetris PRIVATE
    ${PROJECT_SOURCE_DIR}/src/gui
    ${PROJECT_SOURCE_DIR}/src/grid
    ${PROJECT_SOURCE_DIR}/src/utils
    ${PROJECT_SOURCE_DIR}/src/blocks
    ${PROJECT_SOURCE_DIR}/src/game
    ${PROJECT_SOURCE_DIR}/src/process
    ${PROJECT_SOURCE_DIR}/src/media
)

enable_testing()

add_subdirectory(tests/googletest)

add_executable(RunTests
    tests/test_tetris.cpp
    src/gui/TetrisGui.cpp
    src/gui/gui_components/GradientCreator.cpp
    src/gui/gui_components/RoundedRectangleDrawer.cpp
    src/gui/gui_components/Arrow.cpp
    src/grid/Grid.cpp
    src/utils/Coords.cpp
    src/utils/ColorCreator.cpp
    src/utils/exceptions.cpp
    src/blocks/Block.cpp
    src/blocks/Blocks.cpp
    src/game/Game.cpp
    src/game/Score.cpp
    src/process/Process.cpp
    src/media/FontLoader.cpp
    src/media/AudioPlayer.cpp
)

target_link_libraries(RunTests
    gtest
    gtest_main
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
)

include(GoogleTest)
gtest_discover_tests(RunTests)
