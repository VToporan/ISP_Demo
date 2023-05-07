add_library(sidebar "")

target_sources(sidebar
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/sidebar.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/sidebar.hpp
  )

target_include_directories(sidebar
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../
    ${CMAKE_CURRENT_LIST_DIR}/../../
  )

target_compile_options(sidebar PRIVATE -fPIC)

target_link_libraries(sidebar PRIVATE filters)
