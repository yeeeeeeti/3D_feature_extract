# Install script for directory: D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bin/asiUI.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bind/asiUI.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bini/asiUI.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xLibraryx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/lib/asiUI.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/bin" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bin/asiUI.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xLibraryx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/libd" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/libd/asiUI.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/bind" TYPE SHARED_LIBRARY FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bind/asiUI.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/bind" TYPE FILE FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/../../win64/vc12/bind/asiUI.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/asiUI.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_IParamEditor.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_IStatusBar.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_ItemRoles.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_HeaderViewAPI.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_ParamEditorImpl.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_ParameterEditorItem.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_StatusBarImpl.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_WidgetFactory.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_BgColorDialog.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_ColorButton.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_Console.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_ControlsAnalysis.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_ControlsAnalysisListener.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_ControlsMesh.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_ControlsMeshListener.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_ControlsModeling.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_ControlsModelingListener.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_ControlsPart.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_ControlsPartListener.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_EvalButton.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_LineEdit.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_ObjectBrowser.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_ParameterEditor.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_ParameterEditorDelegate.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_ParameterEditorListener.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_ParameterEditorView.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_StatusBar.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/controls/asiUI_StyledTextEdit.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/salome/QDS.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/salome/QDS_Validator.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/salome/Qtx.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/salome/SUIT_TreeSync.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/salome/QDS_CheckBox.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/salome/QDS_ComboBox.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/salome/QDS_Datum.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/salome/QDS_LineEdit.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/salome/QDS_RadioBox.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/salome/QDS_SpinBox.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/salome/QDS_SpinBoxDbl.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/salome/QDS_TextEdit.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/salome/QtxColorButton.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/salome/QtxComboBox.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/salome/QtxDoubleSpinBox.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/salome/QtxIntSpinBox.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/salome/SUIT_PopupClient.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumFormat.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumViewApi.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumViewItem.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_Datum.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumCheckBox.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumColorEdit.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumColorItem.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumComboBox.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumCustomSelector.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumDateEdit.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumDelegate.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumItemEditor.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumLabel.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumLineEdit.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumPathEdit.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumPathItem.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumRadioBox.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumSelector.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumSpinBox.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumSpinBoxDbl.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumViewBase.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumViewDelegate.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/datum/asiUI_DatumViewModel.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/dialogs/asiUI_DialogCommands.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/dialogs/asiUI_DialogCommandsDelegate.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/dialogs/asiUI_DialogEuler.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/dialogs/asiUI_DialogFindEdge.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/dialogs/asiUI_DialogFindFace.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/dialogs/asiUI_DialogGapFilling.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/dialogs/asiUI_DialogGeomDef.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/dialogs/asiUI_DialogOCAFDump.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/dialogs/asiUI_DialogPipelines.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/dialogs/asiUI_DialogRefineTessellation.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/dialogs/asiUI_DialogSewing.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/dialogs/asiUI_DialogSmoothAngleTol.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/dialogs/asiUI_DialogSTEP.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/dialogs/asiUI_DialogSTEPDelegate.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/dialogs/asiUI_DialogTopoGraphDepth.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/graphs/asiUI_AAGAdaptor.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/graphs/asiUI_HistoryGraphAdaptor.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/graphs/asiUI_TopoGraphAdaptor.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/graphs/asiUI_HistoryGraph.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/graphs/asiUI_HistoryGraphItem.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/graphs/asiUI_PartGraph.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/graphs/asiUI_PartGraphItem.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/plots/asiUI_Plot2d.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/interaction/asiUI_PickEdgeCallback.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/interaction/asiUI_PickFacetCallback.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/interaction/asiUI_RotationCallback.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/interaction/asiUI_ViewerCallback.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/interaction/asiUI_AddCurveHandleCallback.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/interaction/asiUI_BaseCurveCallback.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/interaction/asiUI_MoveCurveHandleCallback.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/interaction/asiUI_PartCallback.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/interaction/asiUI_PDomainCallback.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/interaction/asiUI_PickCallback.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/interaction/asiUI_PickContourCallback.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/interaction/asiUI_PickCurveCallback.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/utils/asiUI_Common.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/utils/asiUI_CommonFacilities.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/utils/asiUI_DataAdaptor.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/utils/asiUI_IV.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/utils/asiUI_Logger.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/utils/asiUI_OverrideCursor.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/utils/asiUI_PrimDataAdaptor.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/utils/asiUI_OverrideCursor.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/utils/asiUI_PrimDataView.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/utils/asiUI_ProgressListener.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/utils/asiUI_ProgressNotifier.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/utils/asiUI_UnitManager.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/framework/include" TYPE FILE FILES
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/viewers/asiUI_Viewer.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/viewers/asiUI_Viewer3dListener.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/viewers/asiUI_ViewerCurve2d.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/viewers/asiUI_ViewerDomain.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/viewers/asiUI_ViewerDomainListener.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/viewers/asiUI_ViewerFuncUnivariate.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/viewers/asiUI_ViewerHost.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/viewers/asiUI_ViewerHostListener.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/viewers/asiUI_ViewerPart.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/viewers/asiUI_ViewerPartListener.h"
    "D:/WeNext3D/AnalysisSitus-v0.3.0/src/asiUI/viewers/asiUI_VtkWindow.h"
    )
endif()

