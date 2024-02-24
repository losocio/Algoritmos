cmake_minimum_required (VERSION 2.8.11)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (matriz)
add_executable (matriz main.cpp Matriz.h Matriz.cpp)
target_link_libraries(matriz pthread)