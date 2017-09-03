cmake_minimum_required(VERSION 3.6)
project(Common_Functions)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set(SOURCE_FILES include/strings.h src/strings.c include/numbers.h src/numbers.c include/bitmaps.h src/bitmaps.c include/base64.h src/base64.c include/bitwise.h src/bitwise.c libraries/md5/md5.h libraries/md5/md5.c libraries/png/png-encoding.h libraries/png/png-encoding.c libraries/png/png-decoding.h libraries/png/png-decoding.c libraries/png/png-helper.h libraries/png/png-helper.c libraries/lz4/lz4.h libraries/lz4/lz4.c include/video.h include/array_helper.h src/array_helper.c include/types.h src/types.c include/system.h src/system.c)
set(TEST_SOURCE_FILES test/test_png_decoding.h test/test_png_decoding.c test/test_png_encoding.h test/test_png_encoding.c test/test_strings.h test/test_strings.c test/test_bitwise.h test/test_bitwise.c test/test_md5.h test/test_md5.c test/test_opencv.h test/test_opencv.c test/test_numbers.h test/test_numbers.c test/test_array_helper.h test/test_array_helper.c test/test_lz4.h test/test_lz4.c)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs)
if(CYGWIN)
    # windows cygwin
    message("building for Cygwin")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/cygwin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/cygwin)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/bin/cygwin)
elseif(APPLE)
    # apple
    message("building for Apple")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/apple)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/apple)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/bin/apple)
else()
    # unix
    message("building for Unix")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/unix)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/unix)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/bin/unix)
endif()

### MAKING LIBRARIES ###
# include current project headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libraries)

# OpenCV library import
if(CYGWIN)
    # windows cygwin
    #set(OpenCV_DIR "C:/opencv/build/x64/vc14/lib")
    set(OpenCV_DIR "C:/opencv/cygwin")
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
    #include_directories("C:/opencv/build/include")
    include_directories(${OpenCV_INCLUDE_DIRS})
endif()
# required both on unix (macOS) and windows cygwin
find_package( OpenCV REQUIRED core imgproc highgui)
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui)

# subprojects paths
set(ZLIB_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../zlib-1.2.8)
set(ZLIB_BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../zlib-1.2.8/outputs)
set(LIBPNG_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../libpng-1.6.24)
set(LIBPNG_BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../libpng-1.6.24/outputs)

# add subprojects
add_subdirectory( # Specifies the directory of the CMakeLists.txt file.
                  ${LIBPNG_SRC_DIR}
                  # Specifies the directory for the build outputs.
                  ${LIBPNG_BUILD_DIR} )

# include header files of subprojects
include_directories(${ZLIB_SRC_DIR}/include)
include_directories(${LIBPNG_SRC_DIR}/include)

# current project shared and static libraries creation
# SHARED
add_library(Common_Functions_Lib SHARED ${SOURCE_FILES})
set_target_properties(Common_Functions_Lib PROPERTIES OUTPUT_NAME common_functions)
target_link_libraries(Common_Functions_Lib ${OpenCV_LIBS})
target_link_libraries(Common_Functions_Lib zlib_Lib)
target_link_libraries(Common_Functions_Lib libpng_Lib)

# STATIC
add_library(Common_Functions_Lib_Static ${SOURCE_FILES})
set_target_properties(Common_Functions_Lib_Static PROPERTIES OUTPUT_NAME common_functions)
target_link_libraries(Common_Functions_Lib_Static ${OpenCV_LIBS})
target_link_libraries(Common_Functions_Lib_Static zlib_Lib_Static)
target_link_libraries(Common_Functions_Lib_Static libpng_Lib_Static)

### MAKING EXECUTABLE ###
# copy resources required by executable
file(COPY test/resources DESTINATION test)
file(COPY test/resources DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test)

# executable's libraries paths
set(UNIT_TESTS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../unit_tests)
set(COMPARERS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../comparers)
if(CYGWIN)
    # windows cygwin
    set(UNIT_TESTS_LIB_PATH ${UNIT_TESTS_SRC_DIR}/outputs/lib/cygwin/libunit_tests.so)
    set(COMPARERS_LIB_PATH ${COMPARERS_SRC_DIR}/outputs/lib/cygwin/libcomparers.so)
elseif(APPLE)
    # apple
    set(UNIT_TESTS_LIB_PATH ${UNIT_TESTS_SRC_DIR}/outputs/lib/apple/libunit_tests.dylib)
    set(COMPARERS_LIB_PATH ${COMPARERS_SRC_DIR}/outputs/lib/apple/libcomparers.dylib)
else()
    # unix
    set(UNIT_TESTS_LIB_PATH ${UNIT_TESTS_SRC_DIR}/outputs/lib/unix/libunit_tests.so)
    set(COMPARERS_LIB_PATH ${COMPARERS_SRC_DIR}/outputs/lib/unix/libcomparers.so)
endif()
add_library(Unit_Test_Lib SHARED IMPORTED)
set_target_properties( Unit_Test_Lib PROPERTIES IMPORTED_LOCATION ${UNIT_TESTS_LIB_PATH} )
add_library(CF_Comparers_Lib SHARED IMPORTED)
set_target_properties( CF_Comparers_Lib PROPERTIES IMPORTED_LOCATION ${COMPARERS_LIB_PATH} )

# executable's libraries include headers
include_directories( ${UNIT_TESTS_SRC_DIR}/include )
include_directories( ${COMPARERS_SRC_DIR}/include )

# current project executable creation
add_executable(Common_Functions src/main.c ${TEST_SOURCE_FILES})
set_target_properties(Common_Functions PROPERTIES OUTPUT_NAME common_functions)
target_link_libraries(Common_Functions Common_Functions_Lib)
target_link_libraries(Common_Functions Unit_Test_Lib)
target_link_libraries(Common_Functions CF_Comparers_Lib)
