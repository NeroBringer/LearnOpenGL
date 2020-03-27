cmake_minimum_required (VERSION 3.1) 

project (LearnOpenGL)

set (CMAKE_C_STANDARD 99)
set (CMAKE_CXX_STANDARD 11)

find_package(GLM REQUIRED)
message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")
find_package(GLFW3 REQUIRED)
message(STATUS "Found GLFW3 in ${GLFW3_INCLUDE_DIR}")
find_package(ASSIMP REQUIRED)
message(STATUS "Found ASSIMP in ${ASSIMP_INCLUDE_DIR}")

if(WIN32)
  set(LIBS glfw3 opengl32 assimp)
endif(WIN32)

set (CHAPTERS
    mesh
    light
    course1
)

file(GLOB SOURCE 
    "Src/Common/*.h"
    "Src/Common/*.hpp"
    "Src/Common/*.cpp"
)
add_library(Common ${SOURCE})
set(LIBS ${LIBS} Common)

foreach(CHARPTER ${CHAPTERS})
    file(GLOB SOURCE
    "Src/${CHARPTER}/*.h"
    "Src/${CHARPTER}/*.hpp"
    "Src/${CHARPTER}/*.cpp"
    "Src/${CHARPTER}/*.vs"
    "Src/${CHARPTER}/*.fs"
    "Src/${CHARPTER}/*.gs"
    )
    set(NAME CHARPTER)
    add_executable(${NAME} ${SOURCE})
    target_link_libraries(${NAME} ${LIBS})

    if(WIN32)
        set_target_properties(${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${CHAPTER}")
    endif(WIN32)

    # copy shader files to build directory
    file(GLOB SHADERS
    "src/${CHAPTER}/${DEMO}/*.vs"
    # "src/${CHAPTER}/${DEMO}/*.frag"
    "src/${CHAPTER}/${DEMO}/*.fs"
    "src/${CHAPTER}/${DEMO}/*.gs"
    )

    foreach(SHADER ${SHADERS})
        if(WIN32)
            # configure_file(${SHADER} "test")
            add_custom_command(TARGET ${NAME} PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SHADER} $<TARGET_FILE_DIR:${NAME}>)
        elseif(UNIX AND NOT APPLE)
    endforeach(SHADER)
endforeach(CHARPTER)


#通用lib


include_directories("${PROJECT_SOURCE_DIR}/Src/Common")
include_directories("${PROJECT_SOURCE_DIR}/External/${CMAKE_SYSTEM_NAME}/include")

link_directories("${PROJECT_SOURCE_DIR}/External/${CMAKE_SYSTEM_NAME}/lib")

add_subdirectory(Src)