add_library(slider "")

target_sources(slider
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/slider.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/slider.hpp
  )

target_include_directories(slider
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../
    ${CMAKE_CURRENT_LIST_DIR}/../../
  )

target_compile_options(slider PRIVATE -fPIC)

target_link_libraries(slider PRIVATE filters)
