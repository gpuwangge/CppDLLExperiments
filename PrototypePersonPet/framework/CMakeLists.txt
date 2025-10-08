file(GLOB CORE_SOURCES "src/*.cpp")
file(GLOB CORE_HEADERS "include/*.h")

add_library(framework SHARED ${CORE_SOURCES} ${CORE_HEADERS})

# set lib name, remove prefix
set_target_properties(framework PROPERTIES
    OUTPUT_NAME "framework"
    PREFIX ""
)

target_include_directories(framework PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(framework interface)

add_custom_command(TARGET framework POST_BUILD
    #COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:person> ../app/$<CONFIGURATION>/
    COMMAND ${CMAKE_COMMAND} -E echo ">>>>>>>>>>>>>>>>>> Linked framework.dll <<<<<<<<<<<<<<<<<<"
)
