# Install script for directory: D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bin/asiData.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bind/asiData.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bini/asiData.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xLibraryx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/lib/asiData.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bin/asiData.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xLibraryx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/libd" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/libd/asiData.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/bind" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bind/asiData.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/bind" TYPE FILE FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/../../win64/vc12/bind/asiData.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/asiData.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/asiData_ParameterFlags.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/asiData_Partition.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/asiData_RootNode.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_AAGAttr.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_AAGParameter.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_BoundaryEdgesNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_BVHAttr.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_BVHParameter.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_CurvatureCombsNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_CurveNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_EdgeNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_FaceContourNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_FaceNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_FaceNormsNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_NamingAttr.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_NamingParameter.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_PartNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_SurfDeviationNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_SurfNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_TolerantRangeNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_TolerantShapesNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/part/asiData_VertexNode.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/mesh/asiData_TessNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/mesh/asiData_TessNormsNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/mesh/asiData_TriangulationNode.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/iv/asiData_IVCurve2dNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/iv/asiData_IVCurveNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/iv/asiData_IVCurves2dNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/iv/asiData_IVCurvesNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/iv/asiData_IVNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/iv/asiData_IVPoints2dNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/iv/asiData_IVPointSet2dNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/iv/asiData_IVPointSetNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/iv/asiData_IVPointsNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/iv/asiData_IVSurfaceNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/iv/asiData_IVSurfacesNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/iv/asiData_IVTessItemNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/iv/asiData_IVTessNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/iv/asiData_IVTextItemNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/iv/asiData_IVTextNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/iv/asiData_IVTopoItemNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/iv/asiData_IVTopoNode.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/re/asiData_ReCoEdgeNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/re/asiData_ReEdgeNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/re/asiData_ReEdgesNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/re/asiData_RePatchesNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/re/asiData_RePatchNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/re/asiData_ReTopoNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/re/asiData_ReVertexNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/re/asiData_ReVerticesNode.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/misc/asiData_ContourNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/misc/asiData_DesignLawNode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/misc/asiData_FuncAttr.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/misc/asiData_FuncParameter.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/resources" TYPE FILE FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/resources/Plugin")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/resources" TYPE FILE FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiData/resources/Resources")
endif()

