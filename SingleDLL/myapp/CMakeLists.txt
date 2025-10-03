# 应用程序项目
project(MyApp)

# 收集源文件
file(GLOB SRC_FILES "src/*.cpp")

# 创建可执行文件
add_executable(myapp ${SRC_FILES})

# 链接DLL - 使用接口库来避免不必要的依赖
target_link_libraries(myapp PRIVATE mydll_interface mydll)

# 设置调试后缀以便区分
set_target_properties(myapp PROPERTIES
    DEBUG_POSTFIX "_d"
)

# 可选：安装规则
install(TARGETS myapp DESTINATION bin)