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
message(STATUS "execute shell command")
execute_process(
        COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/utils/utils.py
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

file(GLOB_RECURSE SOURCES
        header-folder/*.h
        source-folder/*.cpp
        )

add_executable(algorithms
        main.cpp
        PTA/PTA1105/SpiralMatrix.cpp PTA/PTA1154/VertexColoring.cpp PTA/PTA1104/SumOfNumberSegments.cpp PTA/PTA1109/ProductOfPolynomials.cpp)

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

