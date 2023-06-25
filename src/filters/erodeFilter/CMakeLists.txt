add_library(erodeFilter "")

target_sources(erodeFilter
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/erodeFilter.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/erodeFilter.hpp
  )

target_include_directories(erodeFilter
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../
  )
