cmake_minimum_required(VERSION 3.6)
project(AuPetitCraft)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/client/Launcher.cpp
        src/client/Launcher.h
        src/World.cpp
        src/World.h
        src/Chunk.cpp
        src/Chunk.h
        src/Block.cpp
        src/Block.h
        src/Entity.cpp
        src/Entity.h
        src/GameRenderer.cpp
        src/GameRenderer.h
        src/BlockRender.cpp
        src/BlockRender.h
        src/utils/CustomException.h
        src/TextureManager.cpp
        src/TextureManager.h
        src/Texture.h
        src/Shader.h
        src/Camera.h
        src/client/Controls.cpp src/client/Controls.h src/WorldRender.cpp src/WorldRender.h src/client/RenderEngine.cpp src/client/RenderEngine.h)

# TODO : Include SOIL in app
include_directories(/usr/include/SOIL)

find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(GLEW REQUIRED glew)

include_directories(${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARIES} ${GLEW_LIBRARIES} /usr/lib/libSOIL.a)

add_executable(AuPetitCraft ${SOURCE_FILES})