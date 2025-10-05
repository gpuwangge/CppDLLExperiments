add_library(person SHARED Person.cpp)
target_include_directories(person PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ../interface)
target_link_libraries(person PUBLIC interface)
