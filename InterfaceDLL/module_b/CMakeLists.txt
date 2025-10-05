add_library(module_b SHARED module_b.cpp)
target_include_directories(module_b PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(module_b interface)

# 设置输出名称，移除lib前缀
set_target_properties(module_b PROPERTIES
    OUTPUT_NAME "module_b"
    PREFIX ""
)

if(WIN32)
    target_compile_definitions(module_b PRIVATE MODULE_B_EXPORTS)
endif()


# 编译完成后高亮输出
add_custom_command(
    TARGET module_b POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo ">>> Built module_b.dll <<<"
)