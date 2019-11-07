//-----------------------------------------------------------------------------
// Created on: 01 October 2018
//-----------------------------------------------------------------------------
// Copyright (c) 2018-present, Sergey Slyadnev
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//    * Neither the name of the copyright holder(s) nor the
//      names of all contributors may be used to endorse or promote products
//      derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------

// Own include
#include <asiAlgo_RecognizeBlends.h>

// asiAlgo includes
#include <asiAlgo_AAGIterator.h>
#include <asiAlgo_AttrBlendCandidate.h>
#include <asiAlgo_ExtractFeatures.h>
#include <asiAlgo_FeatureType.h>
#include <asiAlgo_RecognizeBlendFace.h>

#undef COUT_DEBUG
#if defined COUT_DEBUG
  #pragma message("===== warning: COUT_DEBUG is enabled")
#endif

//-----------------------------------------------------------------------------

namespace asiAlgo_AAGIterationRule
{
  //! This rule prevents further iteration starting from faces which are
  //! not recognized as blend candidate faces. The important property of
  //! this rule is that it performs actual recognition. That is, the AAG
  //! is enriched with new attributes representing the blend candidates as
  //! a result of iteration.
  class RecognizeBlendCandidates : public Standard_Transient
  {
  public:

    // OCCT RTTI
    DEFINE_STANDARD_RTTI_INLINE(RecognizeBlendCandidates, Standard_Transient)

  public:

    //! Ctor.
    //! \param[in] aag       attributed adjacency graph keeping information on the
    //!                      recognized properties of the model.
    //! \param[in] maxRadius max allowed radius.
    //! \param[in] progress  progress notifier.
    //! \param[in] plottter  imperative plotter.
    RecognizeBlendCandidates(const Handle(asiAlgo_AAG)& aag,
                             const double               maxRadius,
                             ActAPI_ProgressEntry       progress,
                             ActAPI_PlotterEntry        plotter)
    : m_aag(aag), m_fMaxRadius(maxRadius), m_bBlockingModeOn(true)
    {
      m_localReco = new asiAlgo_RecognizeBlendFace(aag, progress, plotter);
    }

  public:

    //! Enables blocking mode of the rule.
    void SetBlockingOn()
    {
      m_bBlockingModeOn = true;
    }

    //! Disables blocking mode of the rule.
    void SetBlockingOff()
    {
      m_bBlockingModeOn = false;
    }

    //! For the given face ID, this method decides whether to check its
    //! neighbors or stop.
    //! \param[in] fid 1-based ID of the face in question.
    //! \return true if the face in question is a gatekeeper for further iteration.
    bool IsBlocking(const int fid)
    {
      // If there are some nodal attributes for this face, we check whether
      // it has already been recognized as a blend candidate.
      if ( m_aag->HasNodeAttributes(fid) )
      {
        Handle(asiAlgo_FeatureAttr)
          attr = m_aag->GetNodeAttribute( fid, asiAlgo_AttrBlendCandidate::GUID() );
        //
        if ( !attr.IsNull() )
          return false; // Allow further iteration.
      }

      // If we are here, then the face in question is not attributed. We can now
      // try to recognize it.
      if ( !m_localReco->Perform(fid, m_fMaxRadius) )
        return m_bBlockingModeOn; // Block further iterations if blocking mode is on.

      return false;
    }

  protected:

    Handle(asiAlgo_AAG)                m_aag;             //!< AAG instance.
    Handle(asiAlgo_RecognizeBlendFace) m_localReco;       //!< Local recognizer.
    double                             m_fMaxRadius;      //!< Max allowed radius.
    bool                               m_bBlockingModeOn; //!< Blocking mode.
  };
};

//-----------------------------------------------------------------------------

asiAlgo_RecognizeBlends::asiAlgo_RecognizeBlends(const TopoDS_Shape&  masterCAD,
                                                 ActAPI_ProgressEntry progress,
                                                 ActAPI_PlotterEntry  plotter)
//
: asiAlgo_Recognizer(masterCAD, NULL, progress, plotter)
{}

//-----------------------------------------------------------------------------

asiAlgo_RecognizeBlends::asiAlgo_RecognizeBlends(const TopoDS_Shape&        masterCAD,
                                                 const Handle(asiAlgo_AAG)& aag,
                                                 ActAPI_ProgressEntry       progress,
                                                 ActAPI_PlotterEntry        plotter)
//
: asiAlgo_Recognizer(masterCAD, aag, progress, plotter)
{}

//-----------------------------------------------------------------------------

asiAlgo_RecognizeBlends::asiAlgo_RecognizeBlends(const Handle(asiAlgo_AAG)& aag,
                                                 ActAPI_ProgressEntry       progress,
                                                 ActAPI_PlotterEntry        plotter)
//
: asiAlgo_Recognizer(aag->GetMasterCAD(), aag, progress, plotter)
{}

//-----------------------------------------------------------------------------

bool asiAlgo_RecognizeBlends::Perform(const double radius)
{
  /* ===========================================
   *  Stage 1: build AAG (if not yet available)
   * =========================================== */

  // Build master AAG if necessary.
  if ( m_aag.IsNull() )
  {
#if defined COUT_DEBUG
    TIMER_NEW
    TIMER_GO
#endif

    // We do not allow smooth transitions here.
    m_aag = new asiAlgo_AAG(m_master, false);

#if defined COUT_DEBUG
    TIMER_FINISH
    TIMER_COUT_RESULT_MSG("Construct AAG")
#endif
  }

  /* =====================================================
   *  Stage 2: iterate AAG attempting to recognize blends
   * ===================================================== */

  // Propagation rule.
  Handle(asiAlgo_AAGIterationRule::RecognizeBlendCandidates)
    itRule = new asiAlgo_AAGIterationRule::RecognizeBlendCandidates(m_aag,
                                                                    radius,
                                                                    m_progress,
                                                                    m_plotter);

  // Rule is used in non-blocking mode to allow full traverse of the model
  // by neighbors.
  itRule->SetBlockingOff();

  // Select seed face.
  const int seedFaceId = 1;

  // Prepare neighborhood iterator with customized propagation rule.
  asiAlgo_AAGNeighborsIterator<asiAlgo_AAGIterationRule::RecognizeBlendCandidates>
    nit(m_aag, seedFaceId, itRule);
  //
  while ( nit.More() )
  {
    nit.Next();
  }

  /* =============================================================
   *  Stage 3: extract features from the attributes hooked in AAG
   * ============================================================= */

  // Prepare tool to extract features from AAG.
  asiAlgo_ExtractFeatures extractor(m_progress, m_plotter);
  extractor.RegisterFeatureType( FeatureType_BlendOrdinary,
                                 asiAlgo_AttrBlendCandidate::GUID() );

  // Extract features.
  Handle(asiAlgo_ExtractFeaturesResult) featureRes;
  if ( !extractor.Perform(m_aag, featureRes) )
  {
    m_progress.SendLogMessage(LogErr(Normal) << "Feature extraction failed.");
    return false;
  }

  // Set result.
  featureRes->GetFaceIndices(m_result.ids);
  return true;
}

//-----------------------------------------------------------------------------

bool asiAlgo_RecognizeBlends::Perform(const int    faceId,
                                      const double radius)
{
  /* ===========================================
   *  Stage 1: build AAG (if not yet available)
   * =========================================== */

  // Build master AAG if necessary.
  if ( m_aag.IsNull() )
  {
#if defined COUT_DEBUG
    TIMER_NEW
    TIMER_GO
#endif

    // We do not allow smooth transitions here.
    m_aag = new asiAlgo_AAG(m_master, false);

#if defined COUT_DEBUG
    TIMER_FINISH
    TIMER_COUT_RESULT_MSG("Construct AAG")
#endif
  }

  // Check if the passed seed face is accessible.
  if ( !m_aag->HasFace(faceId) )
  {
    m_progress.SendLogMessage(LogErr(Normal) << "Face %1 does not exist." << faceId);
    return false;
  }

  /* =====================================================
   *  Stage 2: iterate AAG attempting to recognize blends
   * ===================================================== */

  // Propagation rule.
  Handle(asiAlgo_AAGIterationRule::RecognizeBlendCandidates)
    itRule = new asiAlgo_AAGIterationRule::RecognizeBlendCandidates(m_aag,
                                                                    radius,
                                                                    m_progress,
                                                                    m_plotter);

  // Prepare neighborhood iterator with customized propagation rule.
  int numRecognizedFaces = 0;
  //
  asiAlgo_AAGNeighborsIterator<asiAlgo_AAGIterationRule::RecognizeBlendCandidates>
    nit(m_aag, faceId, itRule);
  //
  for ( ; nit.More(); nit.Next(), ++numRecognizedFaces )
  {
    const int fid = nit.GetFaceId();

    m_plotter.DRAW_SHAPE(m_aag->GetFace(fid), Color_Blue, 1.0, false, "blendCandidate");
  }

  return numRecognizedFaces > 0;
}