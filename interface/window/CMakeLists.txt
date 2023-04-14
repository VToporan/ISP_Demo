add_library(window "")

target_sources(window
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/window.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/window.hpp
  )

target_include_directories(window
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

target_compile_options(window PRIVATE -fPIC)
