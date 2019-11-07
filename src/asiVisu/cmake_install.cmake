# Install script for directory: D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bin/asiVisu.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bind/asiVisu.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bini/asiVisu.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xLibraryx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/lib/asiVisu.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bin/asiVisu.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xLibraryx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/libd" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/libd/asiVisu.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/bind" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bind/asiVisu.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/bind" TYPE FILE FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/../../win64/vc12/bind/asiVisu.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/asiVisu.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/asiVisu_Common.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/asiVisu_MeshDisplayMode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/asiVisu_MeshPrimitive.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/asiVisu_ShapeDisplayMode.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/asiVisu_ShapePrimitive.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/filters/asiVisu_MeshENScalarFilter.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/filters/asiVisu_MeshEScalarFilter.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/filters/asiVisu_MeshEVectorFilter.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/filters/asiVisu_MeshNScalarFilter.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/filters/asiVisu_PointsVectorFilter.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/filters/asiVisu_ShapeDisplayModeFilter.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/filters/asiVisu_ShrinkPolyFilter.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/filters/asiVisu_TriangulationDisplayModeFilter.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_BCurveHandlesPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_BCurveKnotsPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_BCurvePolesPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_BCurveRepersPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_BSurfAxesPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_BSurfKnotsPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_BSurfPolesPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_CurvatureCombsPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_CurvePipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_EdgeCurvePipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_EdgeDomainPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_FaceContourPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_FaceDomainPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_FaceSurfaceIsosPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_FaceSurfaceShadedPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_FuncLevelsPipeline2d.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_FuncLevelsPipeline3d.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_FuncUnivariatePipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_IVSurfacePipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_MeshContourPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_MeshENScalarPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_MeshEScalarPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_MeshEVectorPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_MeshNScalarPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_MeshPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_PartEdgesPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_PartPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_PartPipelineBase.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_Pipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_PointsPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_ShapePipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_SurfaceDeviationPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_TriangulationLinksPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_TriangulationPipeline.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_TriangulationPipelineBase.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/pipelines/asiVisu_VectorsPipeline.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_CalculusLawPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_ContourPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_CurvatureCombsPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_DefaultPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_GeomBoundaryEdgesPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_GeomCurvePrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_GeomEdgePrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_GeomFaceContourPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_GeomFaceNormsPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_GeomFacePrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_GeomSurfPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_IVCurve2dPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_IVCurvePrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_IVPointSet2dPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_IVPointSetPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_IVSurfacePrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_IVTessItemPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_IVTextItemPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_IVTopoItemPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_PartPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_Prs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_PrsManager.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_ReEdgePrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_ReVertexPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_SurfDeviationPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_TessellationNormsPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_TessellationPrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_TolerantRangePrs.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/presentations/asiVisu_TriangulationPrs.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_ContourDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_ContourPointsDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_ContourPolesDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_CurvatureCombsDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_CurveDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_DataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_EdgeDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_FaceContourDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_FaceDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_FaceNormalsDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_FuncDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_FuncUnivariateDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_IVCurve2dDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_IVCurveDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_IVPointSet2dDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_IVPointSetDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_IVSurfaceDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_LawDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_MeshDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_PartDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_PointsDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_PointsFromListDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_ReEdgeCurveDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_ReEdgePolylineDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_ReVertexDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_ShapeDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_SurfaceDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_SurfaceDeviationDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_TessNormalsDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_TriangulationDataProvider.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/providers/asiVisu_VectorsDataProvider.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/selection/asiVisu_InteractorStylePick.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/selection/asiVisu_InteractorStylePick2d.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/selection/asiVisu_NodeInfo.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/selection/asiVisu_PartNodeInfo.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/selection/asiVisu_Selection.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/selection/asiVisu_TriangulationNodeInfo.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_BCurveHandlesSource.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_BCurveKnotsSource.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_BCurvePolesSource.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_BCurveRepersSource.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_BSurfAxesSource.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_BSurfKnotsSource.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_BSurfPolesSource.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_CurvatureCombsSource.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_CurveSource.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_FuncLevelsSource2d.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_FuncLevelsSource3d.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_FuncLevelsSourceBase.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_FuncUnivariateSource.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_MeshSource.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_PCurveSource.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_PDomainSource.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_PointsSource.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_ShapeData.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_ShapeRobustSource.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_ShapeRobustTessellator.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_SurfaceSource.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/sources/asiVisu_TriangulationSource.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/utils/asiVisu_GeomUtils.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/utils/asiVisu_MeshResultUtils.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/utils/asiVisu_MeshUtils.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/utils/asiVisu_Utils.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiVisu/widgets/asiVisu_PlaneWidget.h")
endif()

