cmake_minimum_required(VERSION 3.6)
project(Common_Functions)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set(SOURCE_FILES strings.h strings.c bitmaps.h bitmaps.c base64.h base64.c bitwise.h bitwise.c libraries/md5/md5.h libraries/md5/md5.c libraries/png/png-encoding.h libraries/png/png-encoding.c libraries/png/png-decoding.h libraries/png/png-decoding.c libraries/png/png-helper.h libraries/png/png-helper.c)
set(TEST_SOURCE_FILES test/test_png_decoding.h test/test_png_decoding.c test/test_png_encoding.h test/test_png_encoding.c test/test_strings.h test/test_strings.c test/test_bitwise.h test/test_bitwise.c test/test_md5.h test/test_md5.c)
# libraries paths
set(LIBPNG_PATH /Users/michzio/Developer/MyProjects/BachelorDegree/c/libpng-1.6.24)
set(ZLIB_PATH /Users/michzio/Developer/MyProjects/BachelorDegree/c/zlib-1.2.8)
set(UNIT_TESTS_PATH /Users/michzio/Developer/MyProjects/BachelorDegree/c/unit_tests)

file(COPY test/resources DESTINATION test)

add_library(Common_Functions_Lib SHARED ${SOURCE_FILES})
set_target_properties(Common_Functions_Lib PROPERTIES OUTPUT_NAME common_functions_shared)
target_link_libraries(Common_Functions_Lib ${LIBPNG_PATH}/liblibpng.a)
target_link_libraries(Common_Functions_Lib ${ZLIB_PATH}/libzlib.a)

add_library(Common_Functions_Lib_Static ${SOURCE_FILES})
set_target_properties(Common_Functions_Lib_Static PROPERTIES OUTPUT_NAME common_functions)
target_link_libraries(Common_Functions_Lib_Static ${LIBPNG_PATH}/liblibpng.a)
target_link_libraries(Common_Functions_Lib_Static ${ZLIB_PATH}/libzlib.a)

add_executable(Common_Functions main.c ${TEST_SOURCE_FILES})
target_link_libraries(Common_Functions Common_Functions_Lib_Static)
target_link_libraries(Common_Functions ${UNIT_TESTS_PATH}/libunit_tests.a)