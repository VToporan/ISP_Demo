add_library(gaussianFilter "")

target_sources(gaussianFilter
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/gaussianFilter.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/gaussianFilter.hpp
  )

target_include_directories(gaussianFilter
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../
  )
