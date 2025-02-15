#pragma once

#include "AutoCompClass.h"
#include <wx/regex.h>
#include "XmlFile.h"

class wxFileInputStream;
class wxTextInputStream;

class AutoCompExports;
WX_DEFINE_ARRAY( AutoCompExports*, AutoCompExportsArray );


class AutoCompExports
{
   public:

      AutoCompExports( const wxString& name = wxEmptyString );
      AutoCompExports( const AutoCompExports& exports );
      ~AutoCompExports();

   public:

      const wxString& GetName() const { return m_Name; }

      bool LoadFromDoxygen( const wxString& path );

      bool LoadXml( const wxString& path );
      bool SaveXml( const wxString& path ) const; 

      void Merge( const AutoCompExportsArray& exports );

      static wxString MakeExistNote( const wxString& desc, int exportBits, const AutoCompExportsArray& exports );

      const AutoCompClassArray&     GetClasses() const   { return m_Classes; }
      const AutoCompFunctionArray&  GetFunctions() const { return m_Functions; }

      void GetFunctionsString( wxString* output, wxChar sep ) const;
      void GetClassString( wxString* output, wxChar sep ) const;
      void GetVarsString( wxString* output, wxChar sep ) const;

   protected:

      void _ReadDoxygenGlobalMethods();
      void _ReadDoxygenClass( const wxString& name, const wxString& base );
      bool _ReadDoxygenComment( const wxString& line, wxString& comment );

      static void _LoadClasses( XmlFile& xml, AutoCompClassArray& classes );
      static void _LoadFunctions(XmlFile& xml, const wxString& elem, AutoCompFunctionArray& functions );
      static void _LoadVars(XmlFile& xml, const wxString& elem, AutoCompVarArray& vars );
      static void _SaveClasses(XmlFile& xml, const AutoCompClassArray& classes );
      static void _SaveFunctions(XmlFile& xml, const wxString& elem, const AutoCompFunctionArray& functions );
      static void _SaveVars(XmlFile& xml, const wxString& elem, const AutoCompVarArray& vars );

      wxFileInputStream*   m_InStream;
      wxTextInputStream*   m_TextStream;

      wxRegEx           m_FuncExpr;
      wxRegEx           m_CommentExpr;
      wxRegEx           m_EndExpr;

      wxString                   m_Name;
      AutoCompClassArray         m_Classes;
      AutoCompFunctionArray      m_Functions;
};
