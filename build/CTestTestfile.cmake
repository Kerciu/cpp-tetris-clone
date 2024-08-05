# CMake generated Testfile for 
# Source directory: /home/kerciu/Desktop/tetris-cpp
# Build directory: /home/kerciu/Desktop/tetris-cpp/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
include("/home/kerciu/Desktop/tetris-cpp/build/RunTests[1]_include.cmake")
add_test(RunTests "/home/kerciu/Desktop/tetris-cpp/build/RunTests")
set_tests_properties(RunTests PROPERTIES  _BACKTRACE_TRIPLES "/home/kerciu/Desktop/tetris-cpp/CMakeLists.txt;72;add_test;/home/kerciu/Desktop/tetris-cpp/CMakeLists.txt;0;")
subdirs("tests/googletest")
