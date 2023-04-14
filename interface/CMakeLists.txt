add_library( interface "" )

# target_sources(interface
#   PUBLIC
#   ${CMAKE_CURRENT_LIST_DIR}/*.hpp
#   )

include_directories(BEFORE ${CMAKE_CURRENT_LIST_DIR}/../filters)

target_include_directories(interface
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

add_subdirectory( window )
add_subdirectory( layer )

target_link_libraries(interface
  PRIVATE 
    window
    layer
  )

