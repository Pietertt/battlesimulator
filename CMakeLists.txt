cmake_minimum_required(VERSION 3.4)
project ("battlesimulator")

# FindFreeImage.cmake and FindSDL2.cmake are not part of cmake by default, use modified third-party scripts:
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(SDL2 REQUIRED)
find_package(FreeImage REQUIRED)

# Compile all "*.cpp" files in the root directory:
file(GLOB SOURCES "src/*.cpp", "src/threading/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

# Add warning flags
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)

target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)
target_link_libraries(${PROJECT_NAME} PRIVATE GLEW::GLEW)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
target_link_libraries(${PROJECT_NAME} PRIVATE FreeImage::freeimage)

# AVX2 support (Intel Haswell and higher)
#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-mavx2")

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14 # Require C++ 14
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
