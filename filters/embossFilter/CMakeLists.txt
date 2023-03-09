add_library(embossFilter "")

target_sources(embossFilter
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/embossFilter.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/embossFilter.hpp
  )

target_include_directories(embossFilter
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../
  )
