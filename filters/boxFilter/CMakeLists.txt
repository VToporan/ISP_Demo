add_library(boxFilter "")

target_sources(boxFilter
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/boxFilter.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/boxFilter.hpp
  )

target_include_directories(boxFilter
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )
