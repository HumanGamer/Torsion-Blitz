#include "PreCompiled.h"
#include "AutoCompText.h"

#ifdef _DEBUG 
   #define new DEBUG_NEW 
#endif 

wxCriticalSection AutoCompText::s_DataLock;


AutoCompText::AutoCompText()
   : m_Signaled( false )
{
}

void AutoCompText::Lock()
{ 
   s_DataLock.Enter(); 
}

void AutoCompText::Unlock( bool ClearSignal ) 
{ 
   if ( ClearSignal )
      m_Signaled = false;

   s_DataLock.Leave(); 
}

bool AutoCompText::IsSignaled() const
{
   wxCriticalSectionLocker lock( m_SignalLock );
   return m_Signaled;
}

void AutoCompText::DeleteRange( size_t pos, size_t len )
{
   wxASSERT( pos < m_Data.Len() );
   wxASSERT( pos+len <= m_Data.Len() );

   if ( len == 0 )
      return;

   m_Data.Remove( pos, len );

   wxCriticalSectionLocker lock( m_SignalLock );
   m_Signaled = true;
}

void AutoCompText::InsertRange( size_t pos, const wxString& text )
{
   wxASSERT( pos <= m_Data.Len() );

   size_t len = text.Len();
   if ( len == 0 )
      return;

   m_Data.insert( pos, text );

   wxCriticalSectionLocker lock( m_SignalLock );
   m_Signaled = true;
}

wxChar* AutoCompText::GetWriteBuf( size_t len ) 
{
   wxChar* result = m_Data.GetWriteBuf( len + 1 ); // never allow zero!
   m_Data.UngetWriteBuf( len );

   wxCriticalSectionLocker lock( m_SignalLock );
   m_Signaled = true;

   return result;
}
