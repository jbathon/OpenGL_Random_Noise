cmake_minimum_required(VERSION 3.23)
project(OpenGL_Random_Noise)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/src/*.h ${CMAKE_SOURCE_DIR}/include/*.hpp)
file(GLOB_RECURSE LIBS ${CMAKE_SOURCE_DIR}/lib/*.a)

find_package(OpenGL REQUIRED)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES} src/WindowBuilder.h)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OPENGL_LIBRARIES} -lfreeglut)