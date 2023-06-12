///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/scrolwin.h>
#include <wx/statbmp.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_menubar1;
		wxMenu* m_menu1;
		wxScrolledWindow* m_scrolledWindow2;
		wxPanel* m_panel1;
		wxScrolledWindow* ImageScroller;
		wxStaticBitmap* DisplayImg;
		wxPanel* m_panel2;
		wxStaticText* m_staticText1;
		wxSpinCtrl* QualityControl;
		wxButton* ConvertBtn;
		wxStaticText* m_staticText11;
		wxSpinCtrl* WidthControl;
		wxSpinCtrl* HeightControl;

		// Virtual event handlers, override them in your derived class
		virtual void OnImageOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImageSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnConvertImg( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 734,468 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrameBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ItemPanelBase
///////////////////////////////////////////////////////////////////////////////
class ItemPanelBase : public wxPanel
{
	private:

	protected:
		wxStaticText* TitleLabel;
		wxStaticText* DoneLabel;

	public:

		ItemPanelBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~ItemPanelBase();

};

