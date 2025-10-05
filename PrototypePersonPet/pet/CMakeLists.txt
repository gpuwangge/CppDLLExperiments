add_library(pet SHARED Pet.cpp)
target_include_directories(pet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ../interface)
target_link_libraries(pet PUBLIC interface)
