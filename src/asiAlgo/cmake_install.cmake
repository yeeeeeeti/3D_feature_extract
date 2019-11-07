# Install script for directory: D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bin/asiAlgo.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bind/asiAlgo.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bini/asiAlgo.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xLibraryx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/lib/asiAlgo.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bin/asiAlgo.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xLibraryx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/libd" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/libd/asiAlgo.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/bind" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bind/asiAlgo.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/bind" TYPE FILE FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/../../win64/vc12/bind/asiAlgo.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/asiAlgo.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_BVHAlgo.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_BVHFacets.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_BVHIterator.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_CheckContour.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_CheckToler.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_Classifier.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_ClassifyPointFace.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_CompleteEdgeLoop.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_DesignLaw.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_DivideByContinuity.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_FuncUnivariate.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_HitFacet.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_IntersectCC.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_IntersectCS.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_IntersectionCurveSS.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_IntersectionPointCC.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_IntersectionPointCS.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_IntersectSS.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_Membership.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_ProjectPointOnMesh.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/auxiliary/asiAlgo_ReapproxContour.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/blends/asiAlgo_AttrBlendCandidate.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/blends/asiAlgo_BlendTopoCondition.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/blends/asiAlgo_BlendTopoConditionFF.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/blends/asiAlgo_BlendTopoConditionFFIsolated.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/blends/asiAlgo_BlendType.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/blends/asiAlgo_FindCrossEdges.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/blends/asiAlgo_FindSmoothEdges.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/blends/asiAlgo_FindSpringEdges.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/blends/asiAlgo_FindTermEdges.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/blends/asiAlgo_RecognizeBlendFace.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/blends/asiAlgo_RecognizeBlends.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/blends/asiAlgo_SuppressBlendChain.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/dict/asiAlgo_Dictionary.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/dict/asiAlgo_DictionaryDimension.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/dict/asiAlgo_DictionaryGroup.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/dict/asiAlgo_DictionaryItem.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/dict/asiAlgo_DictionaryUnit.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/dict/asiAlgo_DictionaryUnitSystem.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/dict/salome/DDS.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/dict/salome/DDS_DicGroup.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/dict/salome/DDS_DicItem.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/dict/salome/DDS_Dictionary.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/dict/salome/DDS_KeyWords.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_BRepNormalization.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_BRepNormalizer.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_DeleteEdges.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_DetachFaces.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_Edge2Rebuild.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_Euler.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_EulerKEF.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_EulerKEV.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_EulerKFMV.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_EulerPoincare.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_FindFree.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_FindNonmanifold.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_FindSameHosts.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_FrozenVertices.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_History.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_InvertFaces.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_InvertShells.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_JoinEdges.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_ModBase.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_ModConstructEdge.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_ModEdgeInfo.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_Naming.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_RebuildEdge.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_RehostFaces.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_RepatchFaces.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_SmallEdges.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_SuppressFaces.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/editing/asiAlgo_TopoKill.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_AAG.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_AAGIterator.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_BorderTrihedron.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_CheckDihedralAngle.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_ExtractFeatures.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_ExtractFeaturesResult.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_FeatureAngleType.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_FeatureAttr.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_FeatureAttrAdjacency.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_FeatureAttrAngle.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_FeatureAttrFace.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_FeatureFormulation.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_FeatureType.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_Recognizer.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_TopoAttr.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_TopoAttrLocation.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_TopoAttrName.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_TopoAttrOrientation.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/features/asiAlgo_TopoGraph.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/interop/asiAlgo_FileFormat.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/interop/asiAlgo_IGES.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/interop/asiAlgo_InteropVars.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/interop/asiAlgo_OBJ.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/interop/asiAlgo_PLY.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/interop/asiAlgo_STEP.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/mesh/asiAlgo_MeshCheckInter.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/mesh/asiAlgo_MeshComputeNorms.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/mesh/asiAlgo_MeshConvert.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/mesh/asiAlgo_MeshGen.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/mesh/asiAlgo_MeshInfo.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/mesh/asiAlgo_MeshInterPlane.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/mesh/asiAlgo_MeshLink.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/mesh/asiAlgo_MeshMerge.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/mesh/asiAlgo_MeshOBB.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/mesh/asiAlgo_MeshOffset.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/mesh/asiAlgo_MeshParams.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/mesh/asiAlgo_MeshProjectLine.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/opt/asiAlgo_ArmijoRule.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/opt/asiAlgo_Function.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/opt/asiAlgo_FunctionWithGradient.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/opt/asiAlgo_GradientDescent.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/opt/asiAlgo_IneqOpt.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/opt/asiAlgo_IneqOptParams.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/opt/asiAlgo_IneqSystem.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/opt/asiAlgo_PSO.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/points/asiAlgo_BaseCloud.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/points/asiAlgo_Cloudify.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/points/asiAlgo_CloudRegion.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/points/asiAlgo_KHull2d.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/points/asiAlgo_PlaneOnPoints.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/points/asiAlgo_PlateOnPoints.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/points/asiAlgo_PointCloudUtils.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/points/asiAlgo_PointWithAttr.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/points/asiAlgo_PurifyCloud.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/points/asiAlgo_QuickHull2d.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/points/asiAlgo_ReorientNorms.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/re/asiAlgo_BuildCoonsSurf.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/re/asiAlgo_InterpolateSurfMesh.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/re/asiAlgo_PlateOnEdges.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/utils/asiAlgo_CheckValidity.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/utils/asiAlgo_FileDumper.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/utils/asiAlgo_JSON.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/utils/asiAlgo_Logger.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/utils/asiAlgo_MemChecker.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/utils/asiAlgo_Timer.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/utils/asiAlgo_TimeStamp.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/utils/asiAlgo_Utils.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiAlgo/utils/asiAlgo_Variable.h"
    )
endif()

