cmake_minimum_required(VERSION 3.5)

project(untitled LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OpenCV_DIR "/home/jqzlca/software/opencv_install/lib/cmake/opencv4")
find_package(OpenCV REQUIRED)
include_directories(include ${OpenCV_INCLUDE_DIRS} )

add_executable(untitled main.cpp)
add_executable(untitled2 stereoCamera.cpp)


#add_executable(checkerboard checkerboard.cpp)

target_link_libraries(untitled ${OpenCV_LIBS} )
target_link_libraries(untitled2 ${OpenCV_LIBS} )
