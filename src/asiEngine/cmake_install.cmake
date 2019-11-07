# Install script for directory: D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiEngine

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bin/asiEngine.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bind/asiEngine.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bini/asiEngine.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xLibraryx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/lib/asiEngine.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bin/asiEngine.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xLibraryx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/libd" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/libd/asiEngine.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/bind" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bind/asiEngine.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/bind" TYPE FILE FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiEngine/../../win64/vc12/bind/asiEngine.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiEngine/asiEngine.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiEngine/asiEngine_Base.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiEngine/asiEngine_Curve.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiEngine/asiEngine_Domain.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiEngine/asiEngine_Editing.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiEngine/asiEngine_IV.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiEngine/asiEngine_Model.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiEngine/asiEngine_NodeFlags.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiEngine/asiEngine_Part.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiEngine/asiEngine_RE.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiEngine/asiEngine_Tessellation.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiEngine/asiEngine_TolerantShapes.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiEngine/asiEngine_Triangulation.h"
    )
endif()

