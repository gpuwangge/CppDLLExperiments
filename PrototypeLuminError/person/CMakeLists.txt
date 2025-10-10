file(GLOB PERSON_SOURCES "src/*.cpp")
file(GLOB PERSON_HEADERS "include/*.h")

add_library(person SHARED ${PERSON_SOURCES} ${PERSON_HEADERS})

# set lib name, remove prefix
set_target_properties(person PROPERTIES
    OUTPUT_NAME "person"
    PREFIX ""
)

target_include_directories(person PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(person interface)

add_custom_command(TARGET person POST_BUILD
    #COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:person> ../app/$<CONFIGURATION>/
    COMMAND ${CMAKE_COMMAND} -E echo ">>>>>>>>>>>>>>>>>> Linked person.dll <<<<<<<<<<<<<<<<<<"
)
