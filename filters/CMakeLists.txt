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
add_subdirectory( medianFilter )
add_subdirectory( gaussianFilter )
add_subdirectory( bilateralFilter )
add_subdirectory( erodeFilter )
add_subdirectory( dilateFilter )
add_subdirectory( sobelFilter )
add_subdirectory( cannyFilter )
add_subdirectory( embossFilter )

target_link_libraries(filters
  PRIVATE 
    boxFilter 
    medianFilter 
    gaussianFilter 
    bilateralFilter 
    erodeFilter 
    dilateFilter 
    sobelFilter 
    cannyFilter 
    embossFilter 
  )
