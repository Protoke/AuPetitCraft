cmake_minimum_required(VERSION 3.6)
project(AuPetitCraft)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)

find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(GLEW REQUIRED glew)

include_directories(${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARIES} ${GLEW_LIBRARIES})

add_executable(AuPetitCraft ${SOURCE_FILES})