add_library(lensFilter "")

target_sources(lensFilter
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/lensFilter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../genericFilter.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/lensFilter.hpp
  )

target_include_directories(lensFilter
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../
  )
