cmake_minimum_required(VERSION 3.28)
project(Renderer C)

set(CMAKE_C_STANDARD 17)

add_executable(Renderer main.c
        Renderer/Renderer.c
        Renderer/Renderer.h
        Renderer/Window.c
        Renderer/Window.h
        Renderer/Batcher.c
        Renderer/Batcher.h
        Renderer/MiniRender.h
        Renderer/Shader.h
        Renderer/Shader.c
)

#Glad includes
add_subdirectory(glad)
target_link_libraries(Renderer glad)


#GlFW includes
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(Glfw)
target_link_libraries(Renderer glfw)
