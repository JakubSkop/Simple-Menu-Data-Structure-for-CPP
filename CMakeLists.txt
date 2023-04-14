cmake_minimum_required(VERSION 3.0.0)
project(LearningArea VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(LearningArea ${SRC_FILES} main.cpp)
target_include_directories(LearningArea PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
