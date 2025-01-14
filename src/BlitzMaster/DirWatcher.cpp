#include "PreCompiled.h"
#include "DirWatcher.h"

#ifdef __WXMSW__
   #include "DirWatcherWin9x.h"
   #include "DirWatcherWinNT.h"
#endif

#ifdef _DEBUG 
   #define new DEBUG_NEW 
#endif 


DirWatcher::DirWatcher()
   : m_Impl( NULL )
{
}

DirWatcher::~DirWatcher()
{
   Clear();
}

bool DirWatcher::SetWatch( const wxString& dir, int flags, const wxArrayString& exclude )
{
   #ifdef __WXMSW__

      if ( wxGetOsVersion() == wxWINDOWS_NT )
         m_Impl = new DirWatcherWinNT( 65536 );
      else
         m_Impl = new DirWatcherWin9x;

   #else
      #error NOT IMPLEMENTED!
   #endif

   return m_Impl->SetWatch( dir, flags, exclude );
}

void DirWatcher::Clear()
{
   wxDELETE( m_Impl );
}

int DirWatcher::GetSignaled( wxArrayString* signaled )
{
   if ( !m_Impl )
      return 0;

   return m_Impl->GetSignaled( signaled );
}
