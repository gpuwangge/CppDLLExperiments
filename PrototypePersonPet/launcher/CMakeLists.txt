project(launcher)

file(GLOB CORE_SOURCES "*.cpp")
file(GLOB CORE_HEADERS "*.h")

add_executable(${PROJECT_NAME} ${CORE_SOURCES} ${CORE_HEADERS})

#add_executable(framework-app
    #main.cpp)
    #../app_personPlay/PersonPlay.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/interface)
target_link_libraries(${PROJECT_NAME} PRIVATE interface)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo ">>>>>>>>>>>>>>>>>> Linked ${PROJECT_NAME}.exe <<<<<<<<<<<<<<<<<<"
)


# add_executable(petPlay 
#     main.cpp)
#     #../app_petPlay/PetPlay.cpp)
# target_include_directories(petPlay PRIVATE ${CMAKE_SOURCE_DIR}/interface)
# target_link_libraries(petPlay PRIVATE interface)

# add_custom_command(TARGET petPlay POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E echo ">>>>>>>>>>>>>>>>>> Linked petPlay.exe <<<<<<<<<<<<<<<<<<"
# )

#CMAKE_SOURCE_DIR → 项目根目录
#CMAKE_CURRENT_SOURCE_DIR → 当前 CMakeLists.txt 所在目录

#库类型关键字
#在add_library()里面使用
#- STATIC (默认)
#- SHARED
#- INTERFACE (后面可以为空，因为没源文件)
#- MODULE
#- OBJECT

#属性传播关键字
#在target_include_directories()里使用
#用来传递include地址。换句话说，依赖的target会自动获得include地址。
#- PRIVATE (自用) (默认)
#- PUBLIC (自用他用都可以)
#- INTERFACE (他用) (如果库类型是INTERFACE，属性传播关键字也只能用INTERFACE)
#但即使设置成自用, 其他target也可用手动方式设定include地址。