# Common-Functions-in-C

Windows Cygwin - OpenCV Installation

1. Download opencv 3.1.0 for Windows release from:
http://opencv.org/downloads.html

2. Download MinGW-w64 from:
https://sourceforge.net/projects/mingw-w64/

3. Download CMake-Gui from:
https://cmake.org/download/

4. Install opencv 3.1.0 by extracting it to C:\opencv directory

5. Install MinGW-w64 with configuration:
Version: 6.2.0, Architecture: x86_64, Threads: win32, Exception: sjlj, Buld Version: 1
in directory C:\mingw-w64\x86_64-6.2.0-win32-sjlj-rt_v5-rev1

6. Set system PATH C:\mingw-w64\x86_64-6.2.0-win32-sjlj-rt_v5-rev1\mingw64\bin to use mingw64 compilers

7. Open CMake-Gui program and select C:\opencv\source and C:\opencv\cygwin destination of build

8. In CMake-Gui click Configure and select MinGW compilator and select manually MinGW compilators
for C and C++ from this urls:
C:\mingw-w64\x86_64-6.2.0-win32-sjlj-rt_v5-rev1\mingw64\bin\x86_64-w64-mingw32-gcc.exe
C:\mingw-w64\x86_64-6.2.0-win32-sjlj-rt_v5-rev1\mingw64\bin\x86_64-w64-mingw32-g++.exe

9. Click Configure again to get rid of red entries in CMake-Gui and than click Generate

10. Go to C:\opencv\cygwin directory in cmd.exe and build it using mingw32-make
if compilation error related to standard threads than just commant out line 47 in detection_based_tracker.cpp
i.e. //#define USE_STD_THREADS

11. Use set(OpenCV_DIR "C:/opencv/cygwin") in CMakeLists.txt of current project

12. Important! project need to use /common/cmake/FindOpenCV.make
and set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
and include header files with include_directories(${OpenCV_INCLUDE_DIRS})

13. Important! to run program add to system PATH environment variable
C:\Users\michzio\Developer\MyProjects\BachelorDegree\c\common\opencv-win-dlls


