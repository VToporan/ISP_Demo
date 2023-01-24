add_library( filters "" )

add_subdirectory( testFilter )

target_link_libraries( filters PRIVATE testFilter )
