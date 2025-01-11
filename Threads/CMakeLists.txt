cmake_minimum_required(VERSION 3.10)
project(ThreadsModule)

find_package(Threads REQUIRED)

file(GLOB_RECURSE THREADS_SRC "src/*.cpp")

add_library(ThreadsLib STATIC ${THREADS_SRC})

target_include_directories(ThreadsLib PUBLIC include)

target_link_libraries(ThreadsLib PUBLIC Threads::Threads)
