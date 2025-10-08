file(GLOB PERSON_SOURCES "src/*.cpp")
file(GLOB PERSON_HEADERS "include/*.h")

add_library(play1 SHARED ${PERSON_SOURCES} ${PERSON_HEADERS})

# set lib name, remove prefix
set_target_properties(play1 PROPERTIES
    OUTPUT_NAME "play1"
    PREFIX ""
)

target_include_directories(play1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(play1 interface)

add_custom_command(TARGET play1 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo ">>>>>>>>>>>>>>>>>> Linked play1.dll <<<<<<<<<<<<<<<<<<"
)
