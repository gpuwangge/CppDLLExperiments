# 定义一个函数创建 DLL
function(add_case DLLNAME)
    file(GLOB SOURCES "${DLLNAME}/*.cpp")
    #file(GLOB HEADERS "${DLLNAME}/*.h")

    add_library(${DLLNAME} SHARED ${SOURCES})

    # 去掉默认前缀，保持 DLL 名称
    set_target_properties(${DLLNAME} PROPERTIES
        OUTPUT_NAME ${DLLNAME}
        PREFIX ""
    )

    target_include_directories(${DLLNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_link_libraries(${DLLNAME} interface)

    add_custom_command(TARGET ${DLLNAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo ">>>>>>>>>>>>>>>>>> Linked ${DLLNAME}.dll <<<<<<<<<<<<<<<<<<"
    )
endfunction()

# 调用函数生成两个 DLL
add_case("case001")
add_case("case002")