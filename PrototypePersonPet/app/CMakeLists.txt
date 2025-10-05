add_executable(prototypeApp main.cpp)
target_link_libraries(prototypeApp PRIVATE interface)

add_custom_command(
    TARGET prototypeApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo ">>> Built prototypeApp <<<"
)