cmake_minimum_required(VERSION 3.6)
project(Common_Functions)

# OpenCV library including
find_package( OpenCV REQUIRED core imgproc highgui)
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set(SOURCE_FILES strings.h strings.c numbers.h numbers.c bitmaps.h bitmaps.c base64.h base64.c bitwise.h bitwise.c libraries/md5/md5.h libraries/md5/md5.c libraries/png/png-encoding.h libraries/png/png-encoding.c libraries/png/png-decoding.h libraries/png/png-decoding.c libraries/png/png-helper.h libraries/png/png-helper.c video.h array_helper.h array_helper.c types.h types.c system.h system.c)
set(TEST_SOURCE_FILES test/test_png_decoding.h test/test_png_decoding.c test/test_png_encoding.h test/test_png_encoding.c test/test_strings.h test/test_strings.c test/test_bitwise.h test/test_bitwise.c test/test_md5.h test/test_md5.c test/test_opencv.h test/test_opencv.c test/test_numbers.h test/test_numbers.c test/test_array_helper.h test/test_array_helper.c)
# libraries paths
set(LIBPNG_PATH /Users/michzio/Developer/MyProjects/BachelorDegree/c/libpng-1.6.24)
set(ZLIB_PATH /Users/michzio/Developer/MyProjects/BachelorDegree/c/zlib-1.2.8)
set(COMPARERS_PATH /Users/michzio/Developer/MyProjects/BachelorDegree/c/comparers)
set(UNIT_TESTS_PATH /Users/michzio/Developer/MyProjects/BachelorDegree/c/unit_tests)

file(COPY test/resources DESTINATION test)

add_library(Common_Functions_Lib SHARED ${SOURCE_FILES})
set_target_properties(Common_Functions_Lib PROPERTIES OUTPUT_NAME common_functions_shared)
target_link_libraries(Common_Functions_Lib ${LIBPNG_PATH}/liblibpng.a)
target_link_libraries(Common_Functions_Lib ${ZLIB_PATH}/libzlib.a)
target_link_libraries(Common_Functions_Lib ${OpenCV_LIBS})

add_library(Common_Functions_Lib_Static ${SOURCE_FILES})
set_target_properties(Common_Functions_Lib_Static PROPERTIES OUTPUT_NAME common_functions)
target_link_libraries(Common_Functions_Lib_Static ${LIBPNG_PATH}/liblibpng.a)
target_link_libraries(Common_Functions_Lib_Static ${ZLIB_PATH}/libzlib.a)
target_link_libraries(Common_Functions_Lib_Static ${OpenCV_LIBS})

add_executable(Common_Functions main.c ${TEST_SOURCE_FILES})
target_link_libraries(Common_Functions Common_Functions_Lib_Static)
target_link_libraries(Common_Functions ${COMPARERS_PATH}/libcomparers.a)
target_link_libraries(Common_Functions ${UNIT_TESTS_PATH}/libunit_tests.a)