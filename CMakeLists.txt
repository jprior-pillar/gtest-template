cmake_minimum_required(VERSION 3.22)
set(PROJECT_NAME_STR GtestTemplate)
project(${PROJECT_NAME_STR} C CXX)

# GoogleTest requires at least C++11
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#-------------------
# set common include folder for module
#-------------------
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

#-------------------
# Test
#-------------------
enable_testing()
include_directories(${COMMON_INCLUDES})
add_subdirectory(src)
add_subdirectory(test)
