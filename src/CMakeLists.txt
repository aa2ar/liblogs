set(LIB_PREFIX "")
set(LIBLOGS_TARGET_NAME ${LIB_PREFIX}${CMAKE_PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

file(GLOB_RECURSE SRC "./*.cpp")

include_directories(".")
include_directories("${CMAKE_SOURCE_DIR}/include")

add_library(${LIBLOGS_TARGET_NAME} SHARED ${SRC})
target_link_libraries(${LIBLOGS_TARGET_NAME} pthread)

add_library(${LIBLOGS_TARGET_NAME}-static STATIC ${SRC})

set_target_properties(${LIBLOGS_TARGET_NAME} PROPERTIES VERSION "1.0")
set_target_properties(${LIBLOGS_TARGET_NAME}-static PROPERTIES OUTPUT_NAME ${LIBLOGS_TARGET_NAME})

#add_executable(${CMAKE_PROJECT_NAME}-tests "./tests/main.cpp")
#target_link_libraries(${CMAKE_PROJECT_NAME}-tests ${CMAKE_PROJECT_NAME})

# install
file(GLOB hdr_files ${CMAKE_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}/*.*)
install(TARGETS ${LIBLOGS_TARGET_NAME} ${LIBLOGS_TARGET_NAME}-static DESTINATION lib COMPONENT main)
install(FILES ${hdr_files} DESTINATION /usr/local/include/${CMAKE_PROJECT_NAME} COMPONENT dev)

# package info
set(PKG_VENDOR "aa2ar")
set(PKG_SUMMARY "Basic C++ logging library")
set(PKG_DESCRIPTION "Basic C++ logging library")
set(PKG_CONTACT "Alexander Arefev, alex.arefyev@gmail.com")

# generate packages
include(mkpackage)

