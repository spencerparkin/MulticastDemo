# CMakeLists.txt for the MulticastDemo.

cmake_minimum_required(VERSION 3.27)

project(MulticastDemo)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(WX_WIDGETS_ROOT "E:/wxWidgets")

add_subdirectory(Sender)
add_subdirectory(Receiver)
add_subdirectory(SocketHelper)