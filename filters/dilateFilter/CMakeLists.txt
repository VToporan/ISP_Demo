add_library(dilateFilter "")

target_sources(dilateFilter
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/dilateFilter.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/dilateFilter.hpp
  )

target_include_directories(dilateFilter
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../
  )
