cmake_minimum_required(VERSION 3.9.0)

project(testasio)

find_package(Threads)

set(CMAKE_CXX_STANDARD 11)

add_executable(client src/client.cc)
target_link_libraries(client Threads::Threads)
add_executable(server src/server.cc)
target_link_libraries(server Threads::Threads)
