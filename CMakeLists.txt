cmake_minimum_required(VERSION 3.10)
project(CppLegoLab)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories to the compiler search path.
include_directories(
    ${CMAKE_SOURCE_DIR}/Threads/include
)

# Add subdirectories that contain other CMakeLists.txt files or project files.
add_subdirectory(Threads)

# Declare an executable target named 'CppLegoLab'.
add_executable(CppLegoLab main.cpp)

# Link a target to given libraries.
target_link_libraries(CppLegoLab PRIVATE ThreadsLib)