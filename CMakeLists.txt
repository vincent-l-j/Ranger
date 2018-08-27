cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project(Ranger)
add_executable(ranger "main.cpp" "ranger.cpp" "laser.cpp"
    "radar.cpp" "sonar.cpp" "user_interface.cpp"
    "ranger_fusion_interface.cpp" "ranger_fusion.cpp")
