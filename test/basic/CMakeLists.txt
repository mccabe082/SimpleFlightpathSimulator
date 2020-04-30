cmake_minimum_required(VERSION 3.5)
enable_language(CXX)
project(simple-flightpath-simulator-basic-testing)

### Installation ####################

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/../../bin CACHE PATH "..." FORCE)
endif()

### External Libraries ##############

set(FindModuleDir ${CMAKE_SOURCE_DIR}/CMake
CACHE STRING "path to directory containing the Find<Module>.cmake modules"
)
mark_as_advanced(FindModuleDir)

list(APPEND CMAKE_MODULE_PATH ${FindModuleDir})
find_package(Catch2 REQUIRED MODULE)
find_package(SimpleFlightpathSim REQUIRED CONFIG PATHS ${CMAKE_SOURCE_DIR}/../../bin/cmake)

### Testing #########################

ENABLE_TESTING()
include(CTest)

### Main Body #######################

add_executable(SimpleFlightpathSimBasicTest)

target_sources(SimpleFlightpathSimBasicTest
PRIVATE
  flightpath.test.cpp
)

target_link_libraries(SimpleFlightpathSimBasicTest
PRIVATE
  RRA::SimpleFlightpathSim
  ::Catch2
)

install(TARGETS SimpleFlightpathSimBasicTest
    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}
)

add_test("Simple flightpath sim - end to end testing" ${CMAKE_INSTALL_PREFIX}/SimpleFlightpathSimBasicTest.exe)
