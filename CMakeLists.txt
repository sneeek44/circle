cmake_minimum_required(VERSION 3.28)
project(circle)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.6.1 COMPONENTS graphics audio REQUIRED)
add_executable(circle main.cpp)
target_link_libraries(circle sfml-graphics)
