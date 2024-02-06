cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME Strings)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSION OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable("${PROJECT_NAME}" Strings.cpp)

file(COPY "1_input.txt" "1_output.txt" "2_input.txt" "3_input.txt" "3_output.txt" DESTINATION "/")