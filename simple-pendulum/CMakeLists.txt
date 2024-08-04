cmake_minimum_required(VERSION 3.10)
project(PendulumSimulation)

# Set OpenGL preference to GLVND
if(POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)
endif()

set(OpenGL_GL_PREFERENCE "GLVND")

set(CMAKE_CXX_STANDARD 17)

# Find OpenGL
find_package(OpenGL REQUIRED)
# Find GLUT
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} include)

add_executable(PendulumSimulation src/main.cpp src/pendulum.cpp)
target_link_libraries(PendulumSimulation ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
