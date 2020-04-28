add_library(SimpleFlightpathSim SHARED)

target_include_directories(SimpleFlightpathSim
PRIVATE
  $<INSTALL_INTERFACE:${CMAKE_SOURCE_DIR}/bin>    
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

target_link_libraries(SimpleFlightpathSim
PRIVATE
   scripted6DoFFlight
)

install(TARGETS SimpleFlightpathSim
    EXPORT SimpleFlightpathSimConfig
    RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin
    ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/bin
    LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/bin
    PUBLIC_HEADER DESTINATION ${CMAKE_SOURCE_DIR}/bin
)
install(EXPORT SimpleFlightpathSimConfig
  FILE
    SimpleFlightpathSimConfig.cmake
  NAMESPACE
    RRA::
  DESTINATION
    ${CMAKE_SOURCE_DIR}/bin/cmake/SimpleFlightpathSim
)
