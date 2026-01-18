
cmake_minimum_required(VERSION 3.16)

# 项目名称
project(查错进阶GUI VERSION 1.0.0 LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找Qt6组件
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# 启用Qt的MOC、UIC和RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 添加可执行文件
add_executable(查错进阶GUI 查错进阶GUI.cpp)

# 链接Qt库
target_link_libraries(查错进阶GUI Qt6::Core Qt6::Widgets)

# 如果是Windows平台，添加Windows子系统
if(WIN32)
    set_target_properties(查错进阶GUI PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
endif()
