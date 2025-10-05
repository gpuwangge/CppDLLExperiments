add_library(module_a SHARED module_a.cpp)

# 设置输出名称，移除lib前缀
set_target_properties(module_a PROPERTIES
    OUTPUT_NAME "module_a"
    PREFIX ""
)

target_include_directories(module_a PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(module_a interface)

if(WIN32)
    target_compile_definitions(module_a PRIVATE MODULE_A_EXPORTS)
endif()

# 编译完成后高亮输出
add_custom_command(
    TARGET module_a POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo ">>> Built module_a.dll <<<"
)