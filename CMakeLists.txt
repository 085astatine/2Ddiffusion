cmake_minimum_required(VERSION 3.2)
#set(CMAKE_VERBOSE_MAKEFILE 1)
#
# cmake module Setting
#
set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
    )
#
# Library Setting
#
#   OpenGL
find_package(OpenGL REQUIRED)
#   GLUT
set(GLUT_INCLUDE_DIR
    "GL")
find_package(GLUT REQUIRED)
#   Eigen3
find_package(Eigen3 REQUIRED)

#
# make rule
#
add_executable(2Ddiffusion
        main.cpp)
include_directories(BEFORE
    ${EIGEN3_INCLUDE_DIR}
    )
target_link_libraries(2Ddiffusion
    ${GLUT_LIBRARY}
    ${OPENGL_LIBRARY})
