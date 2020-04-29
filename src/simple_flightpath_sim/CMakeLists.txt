add_library(SimpleFlightpathSim SHARED)

target_include_directories(SimpleFlightpathSim
INTERFACE
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}> 
PRIVATE   
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
)

target_sources(SimpleFlightpathSim
PRIVATE
  ../../include/simple_flightpath_sim/flightpath.h
  flightpath.cpp
)
set_target_properties(SimpleFlightpathSim 
PROPERTIES PUBLIC_HEADER 
  ../../include/simple_flightpath_sim/flightpath.h
)

### EXPERIMENT #################
target_include_directories(SimpleFlightpathSim
PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)
include(GenerateExportHeader)
generate_export_header(SimpleFlightpathSim)
################################

target_link_libraries(SimpleFlightpathSim
PRIVATE
   SimpleWaypointSim
)

install(TARGETS SimpleFlightpathSim
    EXPORT SimpleFlightpathSimConfig
    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}
)

install(
  #FILES ${CURRENT_BINARY_DIR}/simpleflightpathsim_export.h
  FILES ${PROJECT_BINARY_DIR}/src/simple_flightpath_sim/simpleflightpathsim_export.h
  DESTINATION ${CMAKE_INSTALL_PREFIX}
)
install(EXPORT SimpleFlightpathSimConfig
  FILE
    SimpleFlightpathSimConfig.cmake
  NAMESPACE
    RRA::
  DESTINATION
    ${CMAKE_INSTALL_PREFIX}/cmake
)
