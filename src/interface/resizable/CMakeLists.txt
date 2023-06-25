add_library(resizable "")

target_sources(resizable
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/resizable.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/resizable.hpp
  )

target_include_directories(resizable
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/..
  )

target_compile_options(resizable PRIVATE -fPIC)

target_link_libraries(resizable PRIVATE filters)
