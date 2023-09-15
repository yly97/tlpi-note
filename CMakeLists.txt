cmake_minimum_required(VERSION 3.16)
project(tlpi)

# set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -o0)

include_directories(${PROJECT_SOURCE_DIR}/include/)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(LIB_SRC 
    include/error_functions.c
    include/get_num.c)
add_library(tlpi ${LIB_SRC})

add_executable(my_env src/ch06/my_env.c)     

target_link_libraries(my_env tlpi)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
