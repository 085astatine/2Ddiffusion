cmake_minimum_required(VERSION 3.2)
#set(CMAKE_VERBOSE_MAKEFILE 1)

add_definitions("-std=c++11 -Wall -Wextra -pedantic")
# Install Prefix
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install"
                CACHE PATH "default install path" FORCE )
endif()
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
find_package(GLUT REQUIRED)
#   Eigen3
find_package(Eigen3 REQUIRED)
#
# make rule
#
add_executable(2Ddiffusion
    main.cpp)
include_directories(
    ${EIGEN3_INCLUDE_DIR}
    )
target_link_libraries(2Ddiffusion
    field_base
    ${GLUT_LIBRARY}
    ${OPENGL_LIBRARY})

add_library(field_base
    field/field_base.cpp
    field/solver/boundary_base.cpp
    field/solver/solver_base.cpp)
