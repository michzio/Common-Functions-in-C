cmake_minimum_required(VERSION 3.6)
project(Common_Functions)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set(SOURCE_FILES strings.h strings.c base64.h base64.c)

add_library(Common_Functions_Lib SHARED ${SOURCE_FILES})
set_target_properties(Common_Functions_Lib PROPERTIES OUTPUT_NAME common_functions_shared)

add_library(Common_Functions_Lib_Static ${SOURCE_FILES})
set_target_properties(Common_Functions_Lib_Static PROPERTIES OUTPUT_NAME common_functions)

add_executable(Common_Functions main.c)
target_link_libraries(Common_Functions Common_Functions_Lib_Static)