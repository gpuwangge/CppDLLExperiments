file(GLOB PET_SOURCES "src/*.cpp")
file(GLOB PET_HEADERS "include/*.h")

add_library(pet SHARED ${PET_SOURCES} ${PET_HEADERS})
target_include_directories(pet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ../interface)

add_custom_command(TARGET pet POST_BUILD
    #COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:pet> ../app/$<CONFIGURATION>/
    COMMAND ${CMAKE_COMMAND} -E echo ">>>>>>>>>>>>>>>>>> Linked pet.dll <<<<<<<<<<<<<<<<<<"
)
