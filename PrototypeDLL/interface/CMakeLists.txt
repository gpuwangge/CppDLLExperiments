# 接口库 - 只有头文件
add_library(interface INTERFACE)
target_include_directories(interface INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})