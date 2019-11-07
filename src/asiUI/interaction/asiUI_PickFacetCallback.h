//-----------------------------------------------------------------------------
// Created on: 22 September 2016
//-----------------------------------------------------------------------------
// Copyright (c) 2017, Sergey Slyadnev
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

#ifndef asiUI_PickFacetCallback_h
#define asiUI_PickFacetCallback_h

// asiUI includes
#include <asiUI_ViewerCallback.h>

// asiAlgo includes
#include <asiAlgo_BVHFacets.h>

// asiEngine includes
#include <asiEngine_Model.h>

// VTK includes
#pragma warning(push, 0)
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#pragma warning(pop)

//! Callback for picking a facet in 3D viewer.
class asiUI_PickFacetCallback : public asiUI_ViewerCallback
{
public:

  asiUI_EXPORT static asiUI_PickFacetCallback*
    New();

  vtkTypeMacro(asiUI_PickFacetCallback, asiUI_ViewerCallback);

public:

  asiUI_EXPORT virtual void
    Execute(vtkObject*    pCaller,
            unsigned long eventId,
            void*         pCallData);

private:

  asiUI_EXPORT
    asiUI_PickFacetCallback(const Handle(asiAlgo_BVHFacets)& bvh_facets,
                            asiUI_Viewer*                    viewer);

  asiUI_EXPORT
    ~asiUI_PickFacetCallback();

};

#endif