add_library( filters "" )

target_sources(filters
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/genericFilter.cpp
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/genericFilter.hpp
  )

target_include_directories(filters
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

add_subdirectory( boxFilter )

target_link_libraries( filters PRIVATE boxFilter )
