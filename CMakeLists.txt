cmake_minimum_required(VERSION 2.8)

project(writing_great_libraries_presentation CXX)

find_package(Boost)
include_directories(${Boost_INCLUDE_DIR})

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER MATCHES clang OR UNIX OR MINGW OR MSYS OR CYGWIN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")
endif ()

if (UNIX)
   set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
else ()
   set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
endif ()

add_subdirectory(presentation)
