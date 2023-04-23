add_library(roi "")

target_sources(roi
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/roi.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/roi.hpp
  )

target_include_directories(roi
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../../
  )

target_compile_options(roi PRIVATE -fPIC)

target_link_libraries(roi PRIVATE filters)
