cmake_minimum_required(VERSION 3.5)
project(latex2img)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
# add_subdirectory(lib)
add_executable(latex2img
	src/args.cpp
	src/generate_latex_file.cpp
	src/latex2img.cpp
	src/main.cpp
)

