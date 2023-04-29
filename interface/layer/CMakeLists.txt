add_library(layer "")

target_sources(layer
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/layer.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/layer.hpp
  )

target_include_directories(layer
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../
    ${CMAKE_CURRENT_LIST_DIR}/../../
  )

target_compile_options(layer PRIVATE -fPIC)

target_link_libraries(layer PRIVATE filters)
