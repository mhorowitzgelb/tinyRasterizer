cmake_minimum_required(VERSION 3.17)
project(sfml_demo)

set(CMAKE_CXX_STANDARD 17)

add_executable(sfml_demo main.cpp TestClass.cc TestClass.h)
include_directories(/usr/include/SFML)
find_package(SFML COMPONENTS system window graphics REQUIRED)
target_link_libraries(sfml_demo sfml-graphics sfml-audio)