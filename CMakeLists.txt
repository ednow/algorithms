# cmake_minimum_required(VERSION <specify CMake version here>)
project(algorithms)

cmake_minimum_required(VERSION 3.14)
#project(
#        VERSION 3.18
#)
#write_basic_package_version_file(VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)

# add_compile_options("/std:c++latest")
#if (MSVC_VERSION GREATER_EQUAL "1900")
#    include(CheckCXXCompilerFlag)
#    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
#    if (_cpp_latest_flag_supported)
#        add_compile_options("/std:c++latest")
#    endif()
#endif()

#if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 16)
#    set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std:c++latest")
#    set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std:c++latest")
#  endif()

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static=libstdc++")
file(GLOB_RECURSE SOURCES
        header-folder/*.h
        source-folder/*.cpp
        )

add_executable(algorithms
        MISC/recursion_elimination/recursion_elimination.cpp PTA/PTA1001/A_plus_B_Format.cpp main.cpp PTA/PTA1002/A_plus_B_for_Polynomials.cpp PTA/PTA1004/Slim.cpp PTA/PTA1004/CountingLeaves.cpp utils/utils.cpp utils/utils.h)

# 添加头文件
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/googletest/include
        ${CMAKE_CURRENT_SOURCE_DIR}/json/include
        ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

# 添加下级目录，生成.a文件
add_subdirectory( ./googletest)

add_subdirectory( ./json)

set(JSON_BuildTests OFF CACHE INTERNAL "")


# 添加连接库
link_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/googletest
)


# 将目标文件与库文件进行链接
target_link_libraries(algorithms gtest nlohmann_json::nlohmann_json)

