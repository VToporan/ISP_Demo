add_library(testFilter "")

target_sources(testFilter
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/testFilter.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/testFilter.hpp
  )

target_include_directories(testFilter
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )
