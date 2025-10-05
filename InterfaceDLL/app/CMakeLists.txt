add_executable(MyApp main.cpp)
target_link_libraries(MyApp interface)
target_include_directories(MyApp PRIVATE ${CMAKE_SOURCE_DIR}/interface)

# 复制DLL到输出目录
if(WIN32)
    add_custom_command(TARGET MyApp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:module_a>
            $<TARGET_FILE_DIR:MyApp>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:module_b>
            $<TARGET_FILE_DIR:MyApp>
    )
endif()


# 编译完成后高亮输出
add_custom_command(
    TARGET MyApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo ">>> Built MyApp.dll <<<"
)