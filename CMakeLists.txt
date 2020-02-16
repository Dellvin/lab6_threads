cmake_minimum_required(VERSION 3.15)
project(Lab6)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system log log_setup)
include_directories(${Boost_DIRECTORIES})
add_executable(Lab6 main.cpp)
target_link_libraries(Lab6 ${Boost_LIBRARIES})
set(CMAKE_CXX_FLAGS "-g -Wall -DBOOST_LOG_DYN_LINK")