add_library(emptyFilter "")

target_sources(emptyFilter
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/emptyFilter.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/emptyFilter.hpp
  )

target_include_directories(emptyFilter
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../
  )
