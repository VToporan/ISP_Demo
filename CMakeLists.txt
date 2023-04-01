cmake_minimum_required(VERSION 2.8)
project( ISP_Demo )

find_package( OpenCV REQUIRED )
find_package( Qt5Widgets REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})

add_subdirectory(filters)
add_subdirectory(interface)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)
SET(CMAKE_EXPORT_COMPILE_COMMAND ON)

add_executable( IspDemo.exe main.cpp )
target_link_libraries( IspDemo.exe PRIVATE filters interface ${OpenCV_LIBS} Qt5::Widgets )
