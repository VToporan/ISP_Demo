add_library( interface "" )

include_directories(BEFORE ${CMAKE_CURRENT_LIST_DIR}/../filters)

target_include_directories(interface
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

add_subdirectory( window )
add_subdirectory( layer )
add_subdirectory( roi )
add_subdirectory( handlebar )
add_subdirectory( resizable )
add_subdirectory( sidebar )
add_subdirectory( slider )
add_subdirectory( button )

target_link_libraries(interface
  PRIVATE 
    window
    layer
    roi
    handlebar
    resizable
    sidebar
    slider
    button
  )

