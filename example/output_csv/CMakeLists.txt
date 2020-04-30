cmake_minimum_required(VERSION 3.5)
enable_language(CXX)
project(simple-flightpath-simulator-output-csv-example)

### Installation ####################

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/../../bin CACHE PATH "..." FORCE)
endif()

### External Libraries ##############

find_package(SimpleFlightpathSim REQUIRED CONFIG PATHS ${CMAKE_SOURCE_DIR}/../../bin/cmake)

### Main Body #######################

add_executable(SimpleFlightpathSimOutputCSVExample)

target_sources(SimpleFlightpathSimOutputCSVExample
PRIVATE
  flightpath.example.cpp
)

target_link_libraries(SimpleFlightpathSimOutputCSVExample
PRIVATE
  RRA::SimpleFlightpathSim
)

install(TARGETS SimpleFlightpathSimOutputCSVExample
    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}
)
