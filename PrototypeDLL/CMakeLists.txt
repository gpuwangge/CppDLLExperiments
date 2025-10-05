cmake_minimum_required(VERSION 3.10)
project(ModularApp)

set(CMAKE_CXX_STANDARD 17)

# 设置输出目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(interface)
add_subdirectory(module_a)
add_subdirectory(module_b)
add_subdirectory(app)