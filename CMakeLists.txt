cmake_minimum_required(VERSION 2.8)

project(liblogs)

# bin output directory
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )
# lib output directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
# cmake directory
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
# package output directory
set(CPACK_OUTPUT_FILE_PREFIX "${CMAKE_SOURCE_DIR}/deb")

option(BUILD_DEBUG "BUILD_DEBUG" OFF)

if(BUILD_DEBUG)
    set(CMAKE_BUILD_TYPE "DEBUG")
else()
    set(CMAKE_BUILD_TYPE "RELEASE")
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_subdirectory(src)
add_subdirectory(tests)
