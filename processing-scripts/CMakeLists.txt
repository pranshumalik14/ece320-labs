cmake_minimum_required(VERSION 3.10)
project(invert-thresh)

set(CMAKE_CXX_STANDARD 17)
set(OpenCV_DIR /home/pranshumalik14/installation/OpenCV-4.1.0/lib/cmake/opencv4)

find_package(OpenCV REQUIRED)

include_directories(.)

add_executable(invert-thresh img-post-proc.cpp)
target_link_libraries(invert-thresh ${OpenCV_LIBS})