cmake_minimum_required(VERSION 3.10)
project(PersonPetDemo)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(interface)
add_subdirectory(application)
add_subdirectory(person)
add_subdirectory(pet)
add_subdirectory(case)
add_subdirectory(launcher)
