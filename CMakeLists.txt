cmake_minimum_required(VERSION 3.10.0)

project(Twitch)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(glfw3  CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(soil2 CONFIG REQUIRED)

set(target ${PROJECT_NAME})

add_executable(${target}
    ${CMAKE_SOURCE_DIR}/main.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Engine.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Graphics/Texture.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Graphics/Sprite.cpp
    ${CMAKE_SOURCE_DIR}/Engine/IO/Mouse.cpp
    ${CMAKE_SOURCE_DIR}/Engine/IO/Keyboard.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Math/Vector3.cpp
    ${CMAKE_SOURCE_DIR}/Engine/physics/Rigidbody.cpp
)

target_link_libraries(${target} 
    glfw
    spdlog::spdlog_header_only
    "-framework OpenGL"
    soil2
)

set_target_properties(${target} PROPERTIES CXX_STANDARD 17)
