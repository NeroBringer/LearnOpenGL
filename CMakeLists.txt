cmake_minimum_required (VERSION 3.1) 

project (LearnOpenGL)

set (CMAKE_C_STANDARD 99)
set (CMAKE_CXX_STANDARD 11)

MACRO(SUBDIRLIST result curdir)


 FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)


 SET(dirlist"")


 FOREACH(child ${children})


 IF(IS_DIRECTORY ${curdir}/${child})


 LIST(APPEND dirlist ${child})


 ENDIF()


 ENDFOREACH()


 SET(${result} ${dirlist})


ENDMACRO()

set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/External/${CMAKE_SYSTEM_NAME}/include")
set(LIB_DIR "${PROJECT_SOURCE_DIR}/External/${CMAKE_SYSTEM_NAME}/lib")

include_directories("${PROJECT_SOURCE_DIR}/Src/Common")
include_directories("${PROJECT_SOURCE_DIR}/External/${CMAKE_SYSTEM_NAME}/include")

link_directories("${PROJECT_SOURCE_DIR}/External/${CMAKE_SYSTEM_NAME}/lib")

if(WIN32)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
endif(WIN32)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

# find the required packages
find_package(GLM REQUIRED)
message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")
find_package(GLFW3 REQUIRED)
message(STATUS "Found GLFW3 in ${GLFW3_INCLUDE_DIR}")
find_package(ASSIMP REQUIRED)
message(STATUS "Found ASSIMP in ${ASSIMP_INCLUDE_DIR}")
# find_package(SOIL REQUIRED)
# message(STATUS "Found SOIL in ${SOIL_INCLUDE_DIR}")
# find_package(GLEW REQUIRED)
# message(STATUS "Found GLEW in ${GLEW_INCLUDE_DIR}")

set(LIBS glfw3 opengl32 assimp Common libglew32 SOIL)

file(GLOB SOURCE
            "Src/Common/*.hpp"
            "Src/Common/*.cpp"
        )

add_library(Common ${SOURCE})

SUBDIRLIST(sourceSubDirs "${PROJECT_SOURCE_DIR}/Src")

#set(CHAPTERS
#   mesh
#    light
#    course1
#	advanced_opengl
#	FrameBuffer
#	Cubemaps
#	Geometry_Shader
#	Instancing
#)
message(STATUS "subDirs${sourceSubDirs}")
foreach(CHAPTER ${sourceSubDirs})
if (NOT ${CHAPTER} STREQUAL "Common")
file (GLOB SOURCE
"Src/${CHAPTER}/*.hpp"
"Src/${CHAPTER}/*.cpp"
)

set(NAME "${CHAPTER}")
add_executable(${NAME} ${SOURCE})
target_link_libraries(${NAME} ${LIBS})

endif()
endforeach(CHAPTER ${sourceSubDirs})