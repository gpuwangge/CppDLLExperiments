add_executable(prototypeApp main.cpp)
target_include_directories(prototypeApp PRIVATE ${CMAKE_SOURCE_DIR}/interface)
target_link_libraries(prototypeApp PRIVATE interface)

add_custom_command(
    TARGET prototypeApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo ">>> Built prototypeApp <<<"
)
