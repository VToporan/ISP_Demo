add_library(button "")

target_sources(button
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/button.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/button.hpp
  )

target_include_directories(button
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/..
  )

target_compile_options(button PRIVATE -fPIC)

target_link_libraries(button PRIVATE filters)
