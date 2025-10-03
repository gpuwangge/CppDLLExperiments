# DLL项目
project(MyDLL VERSION 1.0.0)

# 收集源文件
file(GLOB SRC_FILES "src/*.cpp")
file(GLOB HEADER_FILES "include/*.h")

# 创建共享库
add_library(mydll SHARED ${SRC_FILES} ${HEADER_FILES})

# 设置包含目录
target_include_directories(mydll
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# 设置编译定义
target_compile_definitions(mydll 
    PRIVATE MYDLL_EXPORTS
)

# 设置属性
set_target_properties(mydll PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

# 创建接口库来管理头文件依赖
add_library(mydll_interface INTERFACE)
target_include_directories(mydll_interface INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 可选：安装规则
install(TARGETS mydll
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)