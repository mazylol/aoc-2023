cmake_minimum_required(VERSION 3.22)
project(day1)

add_executable(${PROJECT_NAME} main.cpp)

add_custom_target(copy_input
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/input.txt
        ${CMAKE_BINARY_DIR}/Debug/input.txt
        COMMENT "Copying input to build directory"
)

add_dependencies(${PROJECT_NAME} copy_input)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)