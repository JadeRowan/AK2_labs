cmake_minimum_required(VERSION "3.16.3")

project(lab2_executable)
set(CMAKE_CXX_STANDARD 17)

add_library(lib calculator.cpp calculator.h)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC lib)
