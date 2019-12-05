cmake_minimum_required (VERSION 3.1) 

add_executable(course1 
course1.cpp
)

target_link_libraries(course1 
Common
opengl32
glfw3
libglew32
SOIL
)
