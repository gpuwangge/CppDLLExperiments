project(UtilsDLL VERSION 1.0.0)

# 收集源文件
file(GLOB SRC_FILES "src/*.cpp")
file(GLOB HEADER_FILES "include/*.h")

# 创建共享库
add_library(utilsdll SHARED ${SRC_FILES} ${HEADER_FILES})

# 设置包含目录
target_include_directories(utilsdll
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# 设置编译定义
target_compile_definitions(utilsdll 
    PRIVATE UTILSDLL_EXPORTS
    PUBLIC UTILSDLL_IMPORTS
)

# 链接core DLL - 现在coredll已经定义
target_link_libraries(utilsdll PRIVATE coredll)

# 设置属性
set_target_properties(utilsdll PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

# 创建接口库
add_library(utilsdll_interface INTERFACE)
target_include_directories(utilsdll_interface INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(utilsdll_interface INTERFACE coredll_interface)

message(STATUS "Utils DLL configured")