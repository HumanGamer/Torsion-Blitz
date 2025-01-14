#pragma once

#include <wx/toolbar.h>


class tsToolBar : public wxToolBar
{
public:
   tsToolBar(  wxWindow* parent, 
               wxWindowID id, 
               const wxPoint& pos = wxDefaultPosition, 
               const wxSize& size = wxDefaultSize, 
               long style = wxTB_HORIZONTAL | wxNO_BORDER, 
               const wxString& name = wxPanelNameStr );

   virtual ~tsToolBar();

   virtual bool Realize();

protected:

   /*
   virtual bool OnLeftClick(int toolid, bool toggleDown);
   virtual void OnRightClick(int toolid, long x, long y);
   virtual void OnMouseEnter(int toolid);
   */

   void OnLeftDown( wxMouseEvent& event );
   void OnLeftUp( wxMouseEvent& event );
   void OnMouseMove( wxMouseEvent& event );
   void OnMouseLeave( wxMouseEvent& event );
   

   void OnSysColourChanged( wxSysColourChangedEvent& event );
   void OnPaint( wxPaintEvent& event );
   void OnEraseBackground( wxEraseEvent& event );

   bool m_HasPainted;
   int m_Pressed;
   int m_Selected;

   DECLARE_EVENT_TABLE()
};
