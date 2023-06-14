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
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/checkbox.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/statbmp.h>

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
		wxScrolledWindow* ConvertingImagesScroller;
		wxBoxSizer* ConvertingImagesSizer;
		wxPanel* m_panel2;
		wxStaticText* m_staticText1;
		wxSlider* QualitySlider;
		wxCheckBox* LosslessCheckbox;
		wxStaticText* m_staticText11;
		wxStaticText* m_staticText5;
		wxSpinCtrl* WidthControl;
		wxStaticText* m_staticText6;
		wxSpinCtrl* HeightControl;
		wxButton* ConvertBtn;

		// Virtual event handlers, override them in your derived class
		virtual void OnImageOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQualityChanged( wxScrollEvent& event ) { event.Skip(); }
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
		wxStaticBitmap* IconBitmap;
		wxStaticText* TitleLabel;
		wxStaticText* DoneLabel;

	public:

		ItemPanelBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 765,136 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~ItemPanelBase();

};

