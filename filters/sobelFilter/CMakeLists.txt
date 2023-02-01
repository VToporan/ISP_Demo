add_library(sobelFilter "")

target_sources(sobelFilter
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/sobelFilter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../genericFilter.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/sobelFilter.hpp
  )

target_include_directories(sobelFilter
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../
  )
