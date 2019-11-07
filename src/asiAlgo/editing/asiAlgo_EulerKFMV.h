//-----------------------------------------------------------------------------
// Created on: 14 May (*) 2018
//-----------------------------------------------------------------------------
// Copyright (c) 2018, Sergey Slyadnev
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

#ifndef asiAlgo_EulerKFMV_h
#define asiAlgo_EulerKFMV_h

// asiAlgo includes
#include <asiAlgo_Euler.h>

// OCCT includes
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>

//-----------------------------------------------------------------------------

//! KFMV (Kill Face Make Vertex) Euler operator.
class asiAlgo_EulerKFMV : public asiAlgo_Euler
{
public:

  // OCCT RTTI
  DEFINE_STANDARD_RTTI_INLINE(asiAlgo_EulerKFMV, asiAlgo_Euler)

public:

  //! Constructor.
  //! \param[in] masterCAD full CAD model.
  //! \param[in] face      face to kill.
  //! \param[in] progress  Progress Notifier.
  //! \param[in] plotter   Imperative Plotter
  asiAlgo_EXPORT
    asiAlgo_EulerKFMV(const TopoDS_Shape&  masterCAD,
                      const TopoDS_Face&   face,
                      ActAPI_ProgressEntry progress,
                      ActAPI_PlotterEntry  plotter);

private:

  //! Performs Euler operator.
  //! \param[in] doApply indicates whether to apply modification
  //!                    requests right at the end (true) or let the caller
  //!                    code manage it explicitly (false).
  //! \return true in case of success, false -- otherwise.
  virtual bool perform(const bool doApply);

protected:

  TopoDS_Face m_face; //!< Face to kill.

};

#endif