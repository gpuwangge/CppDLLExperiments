file(GLOB PET_SOURCES "src/*.cpp")
file(GLOB PET_HEADERS "include/*.h")

add_library(pet SHARED ${PET_SOURCES} ${PET_HEADERS})

# set lib name, remove prefix
set_target_properties(pet PROPERTIES
    OUTPUT_NAME "pet"
    PREFIX ""
)

target_include_directories(pet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(pet interface)

add_custom_command(TARGET pet POST_BUILD
    #COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:pet> ../app/$<CONFIGURATION>/
    COMMAND ${CMAKE_COMMAND} -E echo ">>>>>>>>>>>>>>>>>> Linked pet.dll <<<<<<<<<<<<<<<<<<"
)
