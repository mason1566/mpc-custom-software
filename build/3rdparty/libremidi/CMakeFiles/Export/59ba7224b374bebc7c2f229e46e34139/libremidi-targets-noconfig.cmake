#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "libremidi" for configuration ""
set_property(TARGET libremidi APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(libremidi PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/liblibremidi.a"
  )

list(APPEND _cmake_import_check_targets libremidi )
list(APPEND _cmake_import_check_files_for_libremidi "${_IMPORT_PREFIX}/lib/liblibremidi.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
