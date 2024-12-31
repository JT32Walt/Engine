cmake_minimum_required(VERSION 3.9.0)
project(Game VERSION 0.1.0)

link_directories(libs/glfw)

include_directories(libs/glad)
include_directories(libs/KHR)
include_directories(libs/glfw)
include_directories(libs/glm)
include_directories(libs/inc)
include_directories(include)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(Game ${SOURCES})

find_package(OpenGL REQUIRED)
target_link_libraries(Game PRIVATE ${OPENGL_gl_LIBRARY})
target_link_libraries(Game PRIVATE glfw3)

file(COPY resources DESTINATION /)
