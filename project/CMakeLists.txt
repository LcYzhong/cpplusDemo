cmake_minimum_required(VERSION 3.25)
project(projectVscode)

set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")

SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
INCLUDE_DIRECTORIES(./include)

AUX_SOURCE_DIRECTORY(./source/ DIR_SOURCE)

add_executable(demo ${DIR_SOURCE})
