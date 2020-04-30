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

### Install #########################

install(
FILES 
  ${CMAKE_CURRENT_SOURCE_DIR}/johns_mountain_demo.xml
DESTINATION
  ${CMAKE_INSTALL_PREFIX}
)

install(
TARGETS
  SimpleFlightpathSimOutputCSVExample
RUNTIME DESTINATION
  ${CMAKE_INSTALL_PREFIX}
)
