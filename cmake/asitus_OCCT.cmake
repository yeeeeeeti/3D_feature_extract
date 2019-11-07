ASITUS_THIRDPARTY_PRODUCT("OCCT" "" "Standard.hxx" "TKernel")

message (STATUS "... OCCT Include dirs: ${3RDPARTY_OCCT_INCLUDE_DIR}")
message (STATUS "... OCCT Library dirs: ${3RDPARTY_OCCT_LIBRARY_DIR}")
message (STATUS "... OCCT Binary  dirs: ${3RDPARTY_OCCT_DLL_DIR}")

string (REPLACE lib libd 3RDPARTY_OCCT_LIBRARY_DIR_DEBUG ${3RDPARTY_OCCT_LIBRARY_DIR})
if (3RDPARTY_OCCT_LIBRARY_DIR_DEBUG AND EXISTS "${3RDPARTY_OCCT_LIBRARY_DIR_DEBUG}")
  if (WIN32)
    if (NOT EXISTS "${3RDPARTY_OCCT_LIBRARY_DIR_DEBUG}/TKernel.lib")
      set (3RDPARTY_OCCT_LIBRARY_DIR_DEBUG "" CACHE INTERNAL FORCE)
    endif()
  else()
    if (NOT EXISTS "${3RDPARTY_OCCT_LIBRARY_DIR_DEBUG}/libTKernel.so")
      set (3RDPARTY_OCCT_LIBRARY_DIR_DEBUG "" CACHE INTERNAL FORCE)
    endif()
  endif()
endif()

if (WIN32)
  string (REPLACE bin bind 3RDPARTY_OCCT_DLL_DIR_DEBUG ${3RDPARTY_OCCT_DLL_DIR})
  if (3RDPARTY_OCCT_DLL_DIR_DEBUG AND EXISTS "${3RDPARTY_OCCT_DLL_DIR_DEBUG}")
    if (NOT EXISTS "${3RDPARTY_OCCT_DLL_DIR_DEBUG}/TKernel.dll")
      set (3RDPARTY_OCCT_DLL_DIR_DEBUG "" CACHE INTERNAL FORCE)
    endif()
  endif()
endif()

message (STATUS "... OCCT Debug Library dirs: ${3RDPARTY_OCCT_LIBRARY_DIR_DEBUG}")
message (STATUS "... OCCT Debug Binary  dirs: ${3RDPARTY_OCCT_DLL_DIR_DEBUG}")

#--------------------------------------------------------------------------
# Installation
if (WIN32)
  message (STATUS "... OCCT binaries: ${3RDPARTY_OCCT_DLL_DIR}")

  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKBin.dll       DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKBinL.dll      DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKBO.dll        DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKBool.dll      DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKBRep.dll      DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKCAF.dll       DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKCDF.dll       DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKernel.dll     DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKG2d.dll       DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKG3d.dll       DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKGeomAlgo.dll  DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKGeomBase.dll  DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKIGES.dll      DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKLCAF.dll      DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKMath.dll      DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKMesh.dll      DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKOffset.dll    DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKPrim.dll      DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKShHealing.dll DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKSTEP.dll      DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKSTEP209.dll   DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKSTEPAttr.dll  DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKSTEPBase.dll  DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKTopAlgo.dll   DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKXSBase.dll    DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKHLR.dll       DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKFillet.dll    DESTINATION bin)
  install (FILES ${3RDPARTY_OCCT_DLL_DIR}/TKSTL.dll       DESTINATION bin)

endif()