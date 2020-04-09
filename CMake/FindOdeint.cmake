find_path(Odeint_INCLUDE_DIR
NAMES
  boost/numeric/odeint.hpp
PATHS
  ${CMAKE_SOURCE_DIR}/external/odeint-2.7
)

set(Odeint_VERSION "2.7")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Odeint
FOUND_VAR Odeint_FOUND
REQUIRED_VARS
Odeint_INCLUDE_DIR
)

if (Odeint_FOUND AND NOT TARGET ::Odeint)
  add_library(::Odeint INTERFACE IMPORTED)
  set_target_properties(::Odeint PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES
    ${Odeint_INCLUDE_DIR}
  )
endif()

mark_as_advanced(
  Odeint_INCLUDE_DIR
)

