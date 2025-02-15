#pragma once


class tsMenu;

WX_DEFINE_ARRAY( tsMenu*, tsMenuArray );


class tsMenu : public wxMenu
{
public:

   tsMenu( const wxString& title, long style = 0 );
   tsMenu( long style = 0 );
   virtual ~tsMenu();

   wxMenuItem* NewMenuItem( int itemid = wxID_SEPARATOR,
                           const wxString& text = wxEmptyString,
                           const wxString& help = wxEmptyString,
                           wxItemKind kind = wxITEM_NORMAL,
                           wxMenu *subMenu = (wxMenu *)NULL );

   wxMenuItem* AppendIconItem( int id, const wxString& text, const wxBitmap& bmp, const wxString& helpString = wxEmptyString );
   wxMenuItem* AppendCheckIconItem( int id, const wxString& text, const wxBitmap& bmp, const wxString& helpString = wxEmptyString );

   static void OnSysColourChanged();

protected:

   static tsMenuArray   s_AllMenus;

};
