//-----------------------------------------------------------------------------
// Created on: 22 August 2017
// Created by: Sergey SLYADNEV
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

#ifndef asiTcl_Interp_h
#define asiTcl_Interp_h

// asiTcl includes
#include <asiTcl_CommandInfo.h>

// asiAlgo includes
#include <asiAlgo_Variable.h>

// Active Data includes
#include <ActAPI_IModel.h>
#include <ActAPI_IPlotter.h>
#include <ActAPI_IProgressNotifier.h>

// OCCT includes
#include <TCollection_AsciiString.hxx>

#define TCL_ERROR 1
#define TCL_OK 0

#define RETURN_TCL_ERROR(interp) \
  interp->PrintLastError(); \
  return TCL_ERROR;

struct Tcl_Interp; // Forward declaration for Tcl C structure.

//! Tcl interpreter interface in Analysis Situs.
class asiTcl_Interp : public Standard_Transient
{
friend class asiTcl_Plugin;

public:

  //! Type definition for function pointer representing C++ implementation
  //! of Tcl command.
  typedef int (*t_user_func)(const Handle(asiTcl_Interp)& interp,
                             int                          argc,
                             const char**                 argv);

  //! Callback for Tcl.
  struct t_tcl_callback
  {
    //! Ctor accepting Tcl interpreter and user function.
    //! \param[in] interp Tcl interpreter instance.
    //! \param[in] func   user function.
    t_tcl_callback(const Handle(asiTcl_Interp)& interp,
                   t_user_func                  func)
    : Interp (interp),
      Func   (func)
    {}

    //! Invokes user command for the given command line arguments.
    //! \param[in] argc number of arguments.
    //! \param[in] argv arguments.
    //! \return TCL error code (0 == TCL_OK, 1 == TCL_ERROR).
    int Invoke(int          argc,
               const char** argv)
    {
      return this->Func != NULL ? this->Func(this->Interp, argc, argv) : 1;
    }

    Handle(asiTcl_Interp) Interp; //!< Tcl interpreter.
    t_user_func           Func;   //!< User function.
  };

public:

  // OCCT RTTI
  DEFINE_STANDARD_RTTI_INLINE(asiTcl_Interp, Standard_Transient)

public:

  //! Constructor.
  //! \param[in] progress optional progress notifier.
  //! \param[in] plotter  optional imperative plotter.
  asiTcl_EXPORT
    asiTcl_Interp(ActAPI_ProgressEntry progress = NULL,
                  ActAPI_PlotterEntry  plotter  = NULL);

  //! Destructor.
  asiTcl_EXPORT
    ~asiTcl_Interp();

public:

  //! \return Tcl interpreter.
  Tcl_Interp* GetTclInterp() const
  {
    return m_pInterp;
  }

  //! Sets Data Model.
  //! \param[in] model Data Model instance.
  void SetModel(const Handle(ActAPI_IModel)& model)
  {
    m_model = model;
  }

  //! \return Data Model instance.
  const Handle(ActAPI_IModel)& GetModel() const
  {
    return m_model;
  }

  //! Sets imperative plotter.
  //! \param[in] plotter imperative plotter to set.
  void SetPlotter(ActAPI_PlotterEntry plotter)
  {
    m_plotter = plotter;
  }

  //! \return plotter.
  ActAPI_PlotterEntry& GetPlotter()
  {
    return m_plotter;
  }

  //! Sets progress notifier.
  //! \param[in] progress progress notifier to set.
  void SetProgress(ActAPI_ProgressEntry progress)
  {
    m_progress = progress;
  }

  //! \return progress notifier.
  ActAPI_ProgressEntry GetProgress()
  {
    if ( m_bNotifierOn )
      return m_progress;

    return ActAPI_ProgressEntry(); // Empty entry.
  }

  //! Enables notification messages from the interpretor.
  void SetNotifierOn()
  {
    m_bNotifierOn = true;
  }

  //! \return true if notifier is on.
  bool IsNotifierOn() const
  {
    return m_bNotifierOn;
  }

  //! Disables notification messages from the interpretor.
  void SetNotifierOff()
  {
    m_bNotifierOn = false;
  }

public:

  //! Initializes interpreter.
  asiTcl_EXPORT void
    Init();

  //! Prints last error.
  asiTcl_EXPORT void
    PrintLastError();

  //! Evaluates command.
  //! \param[in] cmd command to evaluate.
  //! \return error code (0 == TCL_OK, 1 == TCL_ERROR).
  asiTcl_EXPORT int
    Eval(const TCollection_AsciiString& cmd);

  //! Adds command to Tcl interpreter.
  //! \param[in] name     command name.
  //! \param[in] help     help string.
  //! \param[in] filename filename where command is implemented.
  //! \param[in] group    group the command to add belongs to.
  //! \param[in] func     pointer to function implementing command.
  //! \return true in case of success, false -- otherwise.
  asiTcl_EXPORT bool
    AddCommand(const TCollection_AsciiString& name,
               const TCollection_AsciiString& help,
               const TCollection_AsciiString& filename,
               const TCollection_AsciiString& group,
               t_user_func                    func);

  //! Takes all available commands from Tcl interpreter and pushes their
  //! names together with additional info to the provided output list.
  //! \param[out] commands output list.
  asiTcl_EXPORT void
    GetAvailableCommands(std::vector<asiTcl_CommandInfo>& commands) const;

  //! Default reaction of interpreter when wrong arguments are passed to
  //! a command.
  //! \param[in] cmd name of the command being executed.
  //! \return Tcl error code (1 == TCL_ERROR).
  asiTcl_EXPORT int
    ErrorOnWrongArgs(const char* cmd);

  //! Returns true if the passed command line option specifies the expected key.
  //! \param[in] opt option to check.
  //! \param[in] key keyword to check (without any "-" prefix).
  //! \return true/false.
  asiTcl_EXPORT bool
    IsKeyword(const TCollection_AsciiString& opt,
              const TCollection_AsciiString& key) const;

  //! Checks whether the passed command line arguments contain the given
  //! key.
  //! \param[in] argc number of command line arguments.
  //! \param[in] argv command line arguments.
  //! \param[in] key  keyword in question.
  //! \return true/false.
  asiTcl_EXPORT bool
    HasKeyword(const int                      argc,
               const char**                   argv,
               const TCollection_AsciiString& key) const;

  //! Searches for the specified key in the list of command line arguments.
  //! If such a key exists, its succeeding argument is taken as value.
  //! \param[in]  argc  number of command line arguments.
  //! \param[in]  argv  command line arguments.
  //! \param[in]  key   keyword in question.
  //! \param[out] value value after the keyword.
  //! \return false if there is no such key or there is no value.
  asiTcl_EXPORT bool
    GetKeyValue(const int                      argc,
                const char**                   argv,
                const TCollection_AsciiString& key,
                TCollection_AsciiString&       value) const;

  //! Sets Tcl variable.
  //! \param[in] name variable name.
  //! \param[in] val  variable value.
  template<typename T>
  void SetVar(const char* name,
              const T     val)
  {
    std::string valStr = asiAlgo_Utils::Str::ToString<T>(val);
    this->SetVar( name, valStr.c_str() );
  }

  //! Sets Tcl variable.
  //! \param[in] name variable name.
  //! \param[in] val  variable value.
  asiTcl_EXPORT void
    SetVar(const char* name,
           const char* val);

  //! Appends the passed string to the result of command execution.
  //! \param[in] str string to append.
  //! \return this for subsequent appends.
  asiTcl_EXPORT asiTcl_Interp&
    Append(const char* str);

  //! Appends the passed string to the result of command execution.
  //! \param[in] str string to append.
  //! \return this for subsequent appends.
  asiTcl_EXPORT asiTcl_Interp&
    operator<<(const char* str);

  //! Appends the passed string to the result of command execution.
  //! \param[in] str string to append.
  //! \return this for subsequent appends.
  asiTcl_EXPORT asiTcl_Interp&
    Append(const TCollection_AsciiString& str);

  //! Appends the passed string to the result of command execution.
  //! \param[in] str string to append.
  //! \return this for subsequent appends.
  asiTcl_EXPORT asiTcl_Interp&
    operator<<(const TCollection_AsciiString& str);

  //! Appends the passed string to the result of command execution.
  //! \param[in] str string to append.
  //! \return this for subsequent appends.
  asiTcl_EXPORT asiTcl_Interp&
    Append(const TCollection_ExtendedString& str);

  //! Appends the passed string to the result of command execution.
  //! \param[in] str string to append.
  //! \return this for subsequent appends.
  asiTcl_EXPORT asiTcl_Interp&
    operator<<(const TCollection_ExtendedString& str);

  //! Appends the passed string to the result of command execution.
  //! \param[in] str string to append.
  //! \return this for subsequent appends.
  asiTcl_EXPORT asiTcl_Interp&
    Append(const std::string& str);

  //! Appends the passed string to the result of command execution.
  //! \param[in] str string to append.
  //! \return this for subsequent appends.
  asiTcl_EXPORT asiTcl_Interp&
    operator<<(const std::string& str);

  //! Appends the passed integer to the result of command execution.
  //! \param[in] value integer value to append.
  //! \return this for subsequent appends.
  asiTcl_EXPORT asiTcl_Interp&
    Append(const int value);

  //! Appends the passed integer to the result of command execution.
  //! \param[in] value integer value to append.
  //! \return this for subsequent appends.
  asiTcl_EXPORT asiTcl_Interp&
    operator<<(const int value);

  //! Appends the passed double to the result of command execution.
  //! \param[in] value double value to append.
  //! \return this for subsequent appends.
  asiTcl_EXPORT asiTcl_Interp&
    Append(const double value);

  //! Appends the passed double to the result of command execution.
  //! \param[in] value double value to append.
  //! \return this for subsequent appends.
  asiTcl_EXPORT asiTcl_Interp&
    operator<<(const double value);

  //! Appends the passed integer mask to the result of command execution.
  //! \param[in] mask integer mask value to append.
  //! \return this for subsequent appends.
  asiTcl_EXPORT asiTcl_Interp&
    Append(const TColStd_PackedMapOfInteger& mask);

  //! Appends the passed integer mask to the result of command execution.
  //! \param[in] mask integer mask to append.
  //! \return this for subsequent appends.
  asiTcl_EXPORT asiTcl_Interp&
    operator<<(const TColStd_PackedMapOfInteger& mask);

protected:

  //! Internal method to add command to Tcl interpreter.
  //! \param[in] name     command name.
  //! \param[in] help     help string.
  //! \param[in] filename filename where command is implemented.
  //! \param[in] group    group the command to add belongs to.
  //! \param[in] callback callback.
  //! \return true in case of success, false -- otherwise.
  asiTcl_EXPORT bool
    addCommand(const TCollection_AsciiString& name,
               const TCollection_AsciiString& help,
               const TCollection_AsciiString& filename,
               const TCollection_AsciiString& group,
               t_tcl_callback*                callback);

protected:

  bool                                 m_bNotifierOn; //!< Indicates whether notifier is on/off.
  Tcl_Interp*                          m_pInterp;     //!< Internal pointer to Tcl interpreter.
  std::vector<TCollection_AsciiString> m_plugins;     //!< List of loaded plugins.
  //
  Handle(ActAPI_IModel) m_model;    //!< Data Model instance.
  ActAPI_ProgressEntry  m_progress; //!< Progress sentry.
  ActAPI_PlotterEntry   m_plotter;  //!< Imperative plotter sentry.

};

#endif