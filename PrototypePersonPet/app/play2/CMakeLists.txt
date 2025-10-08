file(GLOB PERSON_SOURCES "src/*.cpp")
file(GLOB PERSON_HEADERS "include/*.h")

add_library(play2 SHARED ${PERSON_SOURCES} ${PERSON_HEADERS})

# set lib name, remove prefix
set_target_properties(play2 PROPERTIES
    OUTPUT_NAME "play2"
    PREFIX ""
)

target_include_directories(play2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(play2 interface)

add_custom_command(TARGET play2 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo ">>>>>>>>>>>>>>>>>> Linked play2.dll <<<<<<<<<<<<<<<<<<"
)
