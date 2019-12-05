cmake_minimum_required (VERSION 3.1) 

add_executable(light 
light.cpp
)

target_link_libraries(light 
Common
opengl32
glfw3
libglew32
SOIL
)
