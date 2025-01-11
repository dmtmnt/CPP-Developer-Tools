cmake_minimum_required(VERSION 3.10)
project(CppLegoLab)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories that contain other components of the project
add_subdirectory(Threads)
# add_subdirectory(Networking)
# add_subdirectory(Graphs)

add_executable(CppLegoLab main.cpp)

# Link the ThreadsLib library which already includes the necessary thread libraries
target_link_libraries(CppLegoLab PRIVATE ThreadsLib)