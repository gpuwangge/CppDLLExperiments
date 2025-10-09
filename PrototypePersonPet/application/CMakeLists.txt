file(GLOB CORE_SOURCES "*.cpp")
file(GLOB CORE_HEADERS "*.h")

add_library(core SHARED ${CORE_SOURCES} ${CORE_HEADERS})

# set lib name, remove prefix
set_target_properties(core PROPERTIES
    OUTPUT_NAME "core"
    PREFIX ""
)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(core interface)

add_custom_command(TARGET core POST_BUILD
    #COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:person> ../app/$<CONFIGURATION>/
    COMMAND ${CMAKE_COMMAND} -E echo ">>>>>>>>>>>>>>>>>> Linked core.dll <<<<<<<<<<<<<<<<<<"
)
