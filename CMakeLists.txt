cmake_minimum_required(VERSION 3.6)
project(Common_Functions)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set(SOURCE_FILES strings.h strings.c numbers.h numbers.c bitmaps.h bitmaps.c base64.h base64.c bitwise.h bitwise.c libraries/md5/md5.h libraries/md5/md5.c libraries/png/png-encoding.h libraries/png/png-encoding.c libraries/png/png-decoding.h libraries/png/png-decoding.c libraries/png/png-helper.h libraries/png/png-helper.c libraries/lz4/lz4.h libraries/lz4/lz4.c video.h array_helper.h array_helper.c types.h types.c system.h system.c)
set(TEST_SOURCE_FILES test/test_png_decoding.h test/test_png_decoding.c test/test_png_encoding.h test/test_png_encoding.c test/test_strings.h test/test_strings.c test/test_bitwise.h test/test_bitwise.c test/test_md5.h test/test_md5.c test/test_opencv.h test/test_opencv.c test/test_numbers.h test/test_numbers.c test/test_array_helper.h test/test_array_helper.c test/test_lz4.h test/test_lz4.c)

if(CYGWIN)
    # windows cygwin
    message("building for Cygwin")
else()
    # unix
    message("building for Unix")
endif()

# OpenCV library including
if(CYGWIN)
    # windows cygwin
    #set(OpenCV_DIR "C:/opencv/build/x64/vc14/lib")
    set(OpenCV_DIR "C:/opencv/cygwin")
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
    #include_directories("C:/opencv/build/include")
    include_directories(${OpenCV_INCLUDE_DIRS})
endif()
# required both on unix (macOS) and windows cygwin
find_package( OpenCV REQUIRED core imgproc highgui)
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui)

# libraries paths
set(LIBPNG_PATH ${CMAKE_SOURCE_DIR}/../libpng-1.6.24)
set(ZLIB_PATH ${CMAKE_SOURCE_DIR}/../zlib-1.2.8)
set(COMPARERS_PATH ${CMAKE_SOURCE_DIR}/../comparers)
set(UNIT_TESTS_PATH ${CMAKE_SOURCE_DIR}/../unit_tests)
if(CYGWIN)
    # windows cygwin
    set(LIBPNG_LIB_PATH ${LIBPNG_PATH}/output/windows/lib/static/liblibpng.a)
    set(ZLIB_LIB_PATH ${ZLIB_PATH}/output/windows/lib/static/libzlib.a)
    set(COMPARERS_LIB_PATH ${COMPARERS_PATH}/output/windows/lib/static/libcomparers.a)
    set(UNIT_TESTS_LIB_PATH ${UNIT_TESTS_PATH}/output/windows/lib/static/libunit_tests.a)
else()
    # unix
    set(LIBPNG_LIB_PATH ${LIBPNG_PATH}/output/unix/lib/static/liblibpng.a)
    set(ZLIB_LIB_PATH ${ZLIB_PATH}/output/unix/lib/static/libzlib.a)
    set(COMPARERS_LIB_PATH ${COMPARERS_PATH}/output/unix/lib/static/libcomparers.a)
    set(UNIT_TESTS_LIB_PATH ${UNIT_TESTS_PATH}/output/unix/lib/static/libunit_tests.a)
endif()

# include header files directories
include_directories(${LIBPNG_PATH})
include_directories(${ZLIB_PATH})

# copy resources
file(COPY test/resources DESTINATION test)

add_library(Common_Functions_Lib SHARED ${SOURCE_FILES})
set_target_properties(Common_Functions_Lib PROPERTIES OUTPUT_NAME common_functions_shared)
target_link_libraries(Common_Functions_Lib ${LIBPNG_LIB_PATH})
target_link_libraries(Common_Functions_Lib ${ZLIB_LIB_PATH})
target_link_libraries(Common_Functions_Lib ${OpenCV_LIBS})

add_library(Common_Functions_Lib_Static ${SOURCE_FILES})
set_target_properties(Common_Functions_Lib_Static PROPERTIES OUTPUT_NAME common_functions)
target_link_libraries(Common_Functions_Lib_Static ${LIBPNG_LIB_PATH})
target_link_libraries(Common_Functions_Lib_Static ${ZLIB_LIB_PATH})
target_link_libraries(Common_Functions_Lib_Static ${OpenCV_LIBS})

add_executable(Common_Functions main.c ${TEST_SOURCE_FILES})
set_target_properties(Common_Functions PROPERTIES OUTPUT_NAME common_functions)
target_link_libraries(Common_Functions Common_Functions_Lib_Static)
target_link_libraries(Common_Functions ${COMPARERS_LIB_PATH})
target_link_libraries(Common_Functions ${UNIT_TESTS_LIB_PATH})

# install targets (executables, shared libraries, static libraries) in current project source directory
add_custom_target(Install_${PROJECT_NAME}
                  $(MAKE) install
                  DEPENDS ${PROJECT_NAME}
                  COMMENT "Installing ${PROJECT_NAME}")

if(CYGWIN)
    # windows cygwin
    set(RUNTIME_DEST_DIR ${CMAKE_SOURCE_DIR}/output/windows/bin)
    set(LIBRARY_DEST_DIR ${CMAKE_SOURCE_DIR}/output/windows/lib)
    set(ARCHIVE_DEST_DIR ${CMAKE_SOURCE_DIR}/output/windows/lib/static)
else()
    # unix
    set(RUNTIME_DEST_DIR ${CMAKE_SOURCE_DIR}/output/unix/bin)
    set(LIBRARY_DEST_DIR ${CMAKE_SOURCE_DIR}/output/unix/lib)
    set(ARCHIVE_DEST_DIR ${CMAKE_SOURCE_DIR}/output/unix/lib/static)
endif()

install(TARGETS Common_Functions Common_Functions_Lib Common_Functions_Lib_Static
        RUNTIME DESTINATION ${RUNTIME_DEST_DIR}
        LIBRARY DESTINATION ${LIBRARY_DEST_DIR}
        ARCHIVE DESTINATION ${ARCHIVE_DEST_DIR})