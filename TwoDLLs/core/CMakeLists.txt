project(CoreDLL VERSION 1.0.0)

# 收集源文件
file(GLOB SRC_FILES "src/*.cpp")
file(GLOB HEADER_FILES "include/*.h")

# 创建共享库
add_library(coredll SHARED ${SRC_FILES} ${HEADER_FILES})

# 设置包含目录
target_include_directories(coredll
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# 设置编译定义
target_compile_definitions(coredll 
    PRIVATE COREDLL_EXPORTS
    PUBLIC COREDLL_IMPORTS
)

# 设置属性
set_target_properties(coredll PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

# 创建接口库
add_library(coredll_interface INTERFACE)
target_include_directories(coredll_interface INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 注意：这里不能直接链接utilsdll，因为utilsdll还没定义
# 依赖关系将在后面处理

message(STATUS "Core DLL configured")