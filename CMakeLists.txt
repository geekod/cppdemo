cmake_minimum_required (VERSION 2.8)

project (cppdemo)

# set debug option
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

# set destination from build to Debug to make it compatible
add_subdirectory(000-template Debug)

#CMAKE_CXX_COMPILER