cmake_minimum_required(VERSION 3.6)
project(AuPetitCraft)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/controller/Game.cpp
        src/controller/Game.h
        src/model/World/World.cpp
        src/model/World/World.h
        src/model/World/Chunk.cpp
        src/model/World/Chunk.h
        src/model/Blocks/Block.cpp
        src/model/Blocks/Block.h
        src/model/Entities/Entity.cpp
        src/model/Entities/Entity.h
        src/graphicEngine/GameRenderer.cpp
        src/graphicEngine/GameRenderer.h
        src/graphicEngine/BlockRender.cpp
        src/graphicEngine/BlockRender.h
        src/model/Blocks/Stone.cpp
        src/model/Blocks/Stone.h
        src/Utilities/CustomException.h
        src/graphicEngine/TextureManager.cpp
        src/graphicEngine/TextureManager.h
        src/graphicEngine/Texture.h
        src/graphicEngine/Shader.h
        src/graphicEngine/Camera.h
        )

# TODO : Include SOIL in app
include_directories(/usr/include/SOIL)

find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(GLEW REQUIRED glew)

include_directories(${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARIES} ${GLEW_LIBRARIES} /usr/lib/libSOIL.a)

add_executable(AuPetitCraft ${SOURCE_FILES})