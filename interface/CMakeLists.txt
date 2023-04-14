add_library( interface "" )

# target_sources(interface
#   PUBLIC
#   ${CMAKE_CURRENT_LIST_DIR}/*.hpp
#   )

target_include_directories(interface
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

add_subdirectory( window )

target_link_libraries(interface
  PRIVATE 
    window
  )

