include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_executable(${PROJECT_NAME}-test main.cpp)
target_link_libraries(${PROJECT_NAME}-test liblogs)
