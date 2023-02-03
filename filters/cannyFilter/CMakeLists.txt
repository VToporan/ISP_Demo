add_library(cannyFilter "")

target_sources(cannyFilter
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/cannyFilter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../genericFilter.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/cannyFilter.hpp
  )

target_include_directories(cannyFilter
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../
  )
