cmake_minimum_required(VERSION 3.2)
project(latex2img)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
# add_subdirectory(lib)
add_executable(latex2img
	src/main.cpp
)

