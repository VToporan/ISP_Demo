add_library(medianFilter "")

target_sources(medianFilter
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/medianFilter.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/medianFilter.hpp
  )

target_include_directories(medianFilter
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../
  )
