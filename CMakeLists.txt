cmake_minimum_required(VERSION 3.5)
enable_language(CXX)
project(simple-flightpath-simulator)

### External Libraries ##############

set(FindModuleDir ${CMAKE_SOURCE_DIR}/cmake
CACHE STRING "path to directory containing the Find<Module>.cmake modules"
)
mark_as_advanced(FindModuleDir)

list(APPEND CMAKE_MODULE_PATH ${FindModuleDir})
find_package(Boost REQUIRED MODULE)
find_package(Catch2 REQUIRED MODULE)
find_package(RapidXML REQUIRED MODULE)
find_package(Microsoft.GSL QUIET CONFIG PATHS ../GSL/build)

#####################################

### Testing #########################
ENABLE_TESTING()
include(CTest)
add_subdirectory(src)
add_subdirectory(test)
#####################################