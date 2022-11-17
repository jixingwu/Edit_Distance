cmake_minimum_required(VERSION 2.8.3)
project(ED)
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(ED_node main.cpp)
target_link_libraries(ED_node ${catkin_LIBRARIES})