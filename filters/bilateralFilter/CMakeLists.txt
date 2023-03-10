add_library(bilateralFilter "")

target_sources(bilateralFilter
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/bilateralFilter.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/bilateralFilter.hpp
  )

target_include_directories(bilateralFilter
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../
  )
