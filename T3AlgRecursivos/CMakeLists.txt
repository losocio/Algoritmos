cmake_minimum_required (VERSION 2.8.11)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project (matriz)
add_executable (matriz main.cpp Matriz.h Matriz.cpp)
target_link_libraries(matriz pthread)

project (palindromo)
add_executable (palindromo Palindromo.cpp)
target_link_libraries(palindromo pthread)

project (raizCuadrada)
add_executable (raizCuadrada RaizCuadrada.cpp)
target_link_libraries(raizCuadrada pthread)

project (combinaciones)
add_executable (combinaciones Combinaciones.cpp)
target_link_libraries(combinaciones pthread)