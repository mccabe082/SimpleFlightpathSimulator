find_path(BoostConfig_INCLUDE_DIR
NAMES
  boost/config.hpp
PATHS
  ${CMAKE_SOURCE_DIR}/external/boostconfig-1.72
)

set(BoostConfig_VERSION "1.72.0")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(BoostConfig
FOUND_VAR BoostConfig_FOUND
REQUIRED_VARS
BoostConfig_INCLUDE_DIR
)

if (BoostConfig_FOUND AND NOT TARGET ::BoostConfig)
  add_library(::BoostConfig INTERFACE IMPORTED)
  set_target_properties(::BoostConfig PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES
    ${BoostConfig_INCLUDE_DIR}
  )
endif()

mark_as_advanced(
  BoostConfig_INCLUDE_DIR
)
