add_library(handlebar "")

target_sources(handlebar
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/handlebar.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/handlebar.hpp
  )

target_include_directories(handlebar
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../
  )

target_compile_options(handlebar PRIVATE -fPIC)
