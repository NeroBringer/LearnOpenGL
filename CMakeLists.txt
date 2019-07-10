cmake_minimum_required (VERSION 3.1) 

project (course1)

set (CMAKE_C_STANDARD 99)
set (CMAKE_CXX_STANDARD 11)

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/External/${CMAKE_SYSTEM_NAME}/include")

link_directories("${PROJECT_SOURCE_DIR}/External/${CMAKE_SYSTEM_NAME}/lib")

add_subdirectory(Src)