cmake_minimum_required(VERSION 2.8)

project(BeC3)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wno-reorder -g")

set(CMAKE_PREFIX_PATH /etc/lib)

find_package(CURL REQUIRED)
include_directories(${CURLCPP_SOURCE_DIR}/include third-party/Bec3-lib/include/)
set(ALL_LIBRARIES Bec3-lib ${CURL_LIBRARY})

add_subdirectory(third-party)
add_subdirectory(template)

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
