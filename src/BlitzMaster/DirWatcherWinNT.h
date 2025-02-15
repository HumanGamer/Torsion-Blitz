#pragma once

#include "DirWatcher.h"


class DirWatcherWinNT : public DirWatcherImp
{
   protected:

      friend class DirWatcher;

      DirWatcherWinNT( size_t bufferSize );

   public:

      virtual ~DirWatcherWinNT();

   public:

      virtual bool SetWatch( const wxString& dir, int flags, const wxArrayString& exclude );
      virtual int GetSignaled( wxArrayString* signaled );
      virtual void Clear();

   protected:

      bool IsExcluded( const wxFileName& path ) const;

      DWORD          m_Flags;
      wxString       m_Dir;
      HANDLE         m_Handle;
      wxArrayString  m_Exclude;
      OVERLAPPED     m_Overlapped;
      wxChar*        m_Buffer;
      const size_t   m_BufferSize;
};
