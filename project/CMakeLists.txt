cmake_minimum_required(VERSION 3.22.1)
project(projectVscode)

set(WINDOW 0)
set(LINUX 1)

if(WINDOW)

message(STATUS "WINDOW")
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
INCLUDE_DIRECTORIES(./include)
AUX_SOURCE_DIRECTORY(./source/ DIR_SOURCE)
add_executable(demo ${DIR_SOURCE})

else(LINUX)

message(STATUS "LINUX")
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

INCLUDE_DIRECTORIES(./copyString)
AUX_SOURCE_DIRECTORY(./copyString string_source)
add_library(copyString SHARED ${string_source})

INCLUDE_DIRECTORIES(./include)
AUX_SOURCE_DIRECTORY(./source/ DIR_SOURCE)

add_executable(demo ${DIR_SOURCE})

target_link_libraries(demo copyString)

endif()