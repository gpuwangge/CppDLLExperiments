project(MainApp)

# 收集源文件
file(GLOB SRC_FILES "src/*.cpp")

# 创建可执行文件
add_executable(mainapp ${SRC_FILES})

# 链接两个DLL
target_link_libraries(mainapp PRIVATE 
    coredll_interface 
    utilsdll_interface
    coredll
    utilsdll
)

# 设置调试后缀
set_target_properties(mainapp PROPERTIES
    DEBUG_POSTFIX "_d"
)

message(STATUS "Main application configured")