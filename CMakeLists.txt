cmake_minimum_required(VERSION 3.12) # wersja może być inna

project(Tetris) # nazwa projektu

# Ustawienia projektu
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dodaj SFML
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

# Katalogi nagłówków
include_directories(${PROJECT_SOURCE_DIR}/src/gui)
include_directories(${PROJECT_SOURCE_DIR}/src/grid)
include_directories(${PROJECT_SOURCE_DIR}/src/main)
include_directories(${PROJECT_SOURCE_DIR}/src/utils)
include_directories(${PROJECT_SOURCE_DIR}/src/blocks)
include_directories(${PROJECT_SOURCE_DIR}/src/game)
include_directories(${PROJECT_SOURCE_DIR}/src/process)
include_directories(${PROJECT_SOURCE_DIR}/src/media)

# Pliki źródłowe
set(SOURCES
    src/main/main.cpp
    src/gui/TetrisGui.cpp
    src/gui/gradient.cpp
    src/gui/rounded_rectangle.cpp
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

# Tworzenie pliku wykonywalnego dla projektu Tetris
add_executable(tetris ${SOURCES})
target_link_libraries(tetris sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

# Konfiguracja GoogleTest
enable_testing() # do odkrywania testów w eksploratorze testów

add_subdirectory(tests/googletest) # dodaj podkatalog googletest
include_directories(tests/googletest/googletest/include) # dla #include <gtest/gtest.h>

# Pliki źródłowe testów
set(TEST_SOURCES
    tests/test_tetris.cpp
    src/gui/TetrisGui.cpp
    src/gui/gradient.cpp
    src/gui/rounded_rectangle.cpp
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

# Tworzenie pliku wykonywalnego dla testów
add_executable(RunTests ${TEST_SOURCES})
target_link_libraries(RunTests gtest gtest_main sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

# Odkrywanie testów
include(GoogleTest)
gtest_discover_tests(RunTests) # odkrywa testy przez zapytanie skompilowanego pliku wykonywalnego testu o enumerację jego testów

# Rejestracja testów
add_test(NAME RunTests COMMAND RunTests)
