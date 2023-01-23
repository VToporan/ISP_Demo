cmake_minimum_required(VERSION 2.8)
project( ISP_Demo )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_subdirectory(filters)

add_executable( IspDemo.exe main.cpp )
target_link_libraries( IspDemo.exe PRIVATE ${OpenCV_LIBS} filters )
