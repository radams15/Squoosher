///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b)
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
#include <wx/toolbar.h>
#include <wx/sizer.h>
#include <wx/scrolwin.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/checkbox.h>
#include <wx/spinctrl.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
#include <wx/gauge.h>

///////////////////////////////////////////////////////////////////////////

#define ID_OPEN 1000
#define ID_ABOUT 1001
#define ID_CONVERT 1002
#define ID_ITEM_PANEL 1003

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_OnImageOpen( wxCommandEvent& event ){ OnImageOpen( event ); }
		void _wxFB_OnAbout( wxCommandEvent& event ){ OnAbout( event ); }
		void _wxFB_OnConvertImg( wxCommandEvent& event ){ OnConvertImg( event ); }
		void _wxFB_OnQualityChanged( wxScrollEvent& event ){ OnQualityChanged( event ); }


	protected:
		wxMenuBar* m_menubar1;
		wxMenu* m_menu1;
		wxMenu* m_menu11;
		wxToolBar* m_toolBar2;
		wxToolBarToolBase* ConvertTool;
		wxScrolledWindow* ConvertingImagesScroller;
		wxBoxSizer* ConvertingImagesSizer;
		wxPanel* m_panel2;
		wxStaticText* m_staticText1;
		wxSlider* QualitySlider;
		wxCheckBox* LosslessCheckbox;
		wxStaticText* m_staticText5;
		wxSpinCtrl* WidthControl;
		wxStaticText* m_staticText6;
		wxSpinCtrl* HeightControl;

		// Virtual event handlers, override them in your derived class
		virtual void OnImageOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnConvertImg( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQualityChanged( wxScrollEvent& event ) { event.Skip(); }


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
		wxGauge* ProgressBar;

	public:

		ItemPanelBase( wxWindow* parent, wxWindowID id = ID_ITEM_PANEL, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 765,136 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~ItemPanelBase();

};

