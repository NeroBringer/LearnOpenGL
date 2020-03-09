cmake_minimum_required (VERSION 3.1) 

add_executable(mesh 
meshMain.cpp
)

target_link_libraries(mesh 
Common
opengl32
glfw3
libglew32
SOIL
assimp
)
