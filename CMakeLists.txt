# cmake_minimum_required(VERSION <specify CMake version here>)
project(algorithms)

cmake_minimum_required(VERSION 3.14)
#project(
#        VERSION 3.18
#)
#write_basic_package_version_file(VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithms
        MISC/recursion_elimination/recursion_elimination.cpp main.cpp)

# 添加头文件
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/googletest/include
)

# 添加下级目录，生成.a文件
add_subdirectory( ./googletest)

# 添加连接库
link_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/googletest
)

# 指定可执行文件的生成位置
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# 指定生成目标
#add_executable(algorithms ${SOUCE_FLIES})

# 将目标文件与库文件进行链接
target_link_libraries(algorithms gtest)
# Link with GoogleTest
#target_link_libraries(algorithms gtest)
#Link with GoogleMock
#target_link_libraries(algorithms gmock )