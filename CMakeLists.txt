## GENERAL ##

cmake_minimum_required(VERSION 2.8)

## WT SPECIFIC ##


#provide wt install directory in environment var or directly
set(WT_INSTALL_DIR $ENV{WT_INSTALL_DIR})
#set(WT_INSTALL_DIR "C:/Program Files/Wt 4.5.1 msvs2019 x64")

## library locations ##
include_directories(${WT_INSTALL_DIR}/include)
link_directories(${WT_INSTALL_DIR}/lib) 
include_directories("C:\\boost\\boost_1_77_0")
include_directories("C:\\boost\\boost_1_77_0\\stage\\lib")

# ASCIIDOC #

IF(ASCIIDOC_EXECUTABLE)
  ADD_DEFINITIONS(-DASCIIDOC_EXECUTABLE="${ASCIIDOC_EXECUTABLE}")
ENDIF(ASCIIDOC_EXECUTABLE)

## PROJECT SPECIFIC ##

PROJECT(BLOG)

LINK_DIRECTORIES("C:\\Program Files\\Wt 4.5.1 msvs2019 x64\\lib")
TARGET_LINK_LIBRARIES(${TARGET} *.*)

## SOURCES ##

file(GLOB_RECURSE sources src/*.cpp*)
file(GLOB_RECURSE headers src/*.h src/*.hpp) # optional, for use in generated IDE projects
file(GLOB divers *.*)

## TARGET ##

set(TARGET blog.wt)
add_executable(${TARGET} ${sources} ${headers} ${divers})

## LINKING ##

set(WT_CONNECTOR "wthttp" CACHE STRING "Connector used (wthttp or wtfcgi)")
set(CMAKE_BUILD_TYPE Debug CACHE STRING " Debug Release RelWithDebInfo MinSizeRel" FORCE )

target_link_libraries(
  ${TARGET}
  optimized ${WT_CONNECTOR} debug ${WT_CONNECTOR}d
  optimized wt              debug wtd
  optimized wtdbo           debug wtdbod
  optimized wtdbosqlite3    debug wtdbosqlite3d
)

## IDE and CONVENIENCE ##

source_group(sources FILES ${sources}) # for some IDE's (MSVC), to show files grouped
source_group(headers FILES ${headers})

## TODO ##

# CRYPT #

IF(CRYPT_LIB_EXISTS)
  TARGET_LINK_LIBRARIES(blog.wt crypt)
ENDIF(CRYPT_LIB_EXISTS)

# Test whether crypt(3) is provided by libc. If it's not, check if
# libcrypt exists and if it provides crypt(3).

#INCLUDE(CheckFunctionExists)
#INCLUDE(CheckLibraryExists)

#CHECK_FUNCTION_EXISTS(crypt CRYPT_EXISTS)
#IF(NOT CRYPT_EXISTS)
#  CHECK_LIBRARY_EXISTS(crypt crypt "" CRYPT_LIB_EXISTS)
#  IF(CRYPT_LIB_EXISTS)
#    SET(CMAKE_REQUIRED_LIBRARIES "crypt")
#    CHECK_FUNCTION_EXISTS(crypt CRYPT_EXISTS)
#  ENDIF(CRYPT_LIB_EXISTS)
#ENDIF(NOT CRYPT_EXISTS)

#IF(CRYPT_LIB_EXISTS)
#  TARGET_LINK_LIBRARIES(${TARGET} crypt)
#ENDIF(CRYPT_LIB_EXISTS)
