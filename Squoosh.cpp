///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Squoosh.h"

#include "res/convert.png.h"
#include "res/open.png.h"

///////////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE( MainFrameBase, wxFrame )
	EVT_MENU( ID_OPEN, MainFrameBase::_wxFB_OnImageOpen )
	EVT_MENU( ID_ABOUT, MainFrameBase::_wxFB_OnAbout )
	EVT_SCROLL( MainFrameBase::_wxFB_OnQualityChanged )
	EVT_BUTTON( wxID_ANY, MainFrameBase::_wxFB_OnConvertImg )
END_EVENT_TABLE()

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 800,600 ), wxDefaultSize );

	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( m_menu1, ID_OPEN, wxString( wxT("Open") ) + wxT('\t') + wxT("ctrl-o"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItem1->SetBitmaps( open_png_to_wx_bitmap() );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_menuItem1->SetBitmap( open_png_to_wx_bitmap() );
	#endif
	m_menu1->Append( m_menuItem1 );

	m_menubar1->Append( m_menu1, wxT("File") );

	m_menu11 = new wxMenu();
	wxMenuItem* m_menuItem11;
	m_menuItem11 = new wxMenuItem( m_menu11, ID_ABOUT, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItem11->SetBitmaps( wxNullBitmap );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_menuItem11->SetBitmap( wxNullBitmap );
	#endif
	m_menu11->Append( m_menuItem11 );

	m_menubar1->Append( m_menu11, wxT("Help") );

	this->SetMenuBar( m_menubar1 );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxHORIZONTAL );

	ConvertingImagesScroller = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL );
	ConvertingImagesScroller->SetScrollRate( 5, 5 );
	ConvertingImagesSizer = new wxBoxSizer( wxVERTICAL );


	ConvertingImagesScroller->SetSizer( ConvertingImagesSizer );
	ConvertingImagesScroller->Layout();
	ConvertingImagesSizer->Fit( ConvertingImagesScroller );
	MainSizer->Add( ConvertingImagesScroller, 4, wxEXPAND | wxALL, 5 );

	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1 = new wxStaticText( m_panel2, wxID_ANY, wxT("Quality"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer4->Add( m_staticText1, 0, wxALL, 5 );

	QualitySlider = new wxSlider( m_panel2, wxID_ANY, 75, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	bSizer4->Add( QualitySlider, 1, wxALL, 5 );


	bSizer3->Add( bSizer4, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );

	LosslessCheckbox = new wxCheckBox( m_panel2, wxID_ANY, wxT("Lossless"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer42->Add( LosslessCheckbox, 0, wxALL, 5 );


	bSizer3->Add( bSizer42, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5 = new wxStaticText( m_panel2, wxID_ANY, wxT("Width"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer9->Add( m_staticText5, 0, wxALL, 5 );

	WidthControl = new wxSpinCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000000, 0 );
	bSizer9->Add( WidthControl, 0, wxALL, 5 );


	bSizer11->Add( bSizer9, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText6 = new wxStaticText( m_panel2, wxID_ANY, wxT("Height"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer91->Add( m_staticText6, 0, wxALL, 5 );

	HeightControl = new wxSpinCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000000, 0 );
	bSizer91->Add( HeightControl, 0, wxALL, 5 );


	bSizer11->Add( bSizer91, 0, wxEXPAND, 5 );


	bSizer41->Add( bSizer11, 0, wxEXPAND, 5 );


	bSizer3->Add( bSizer41, 0, wxEXPAND, 5 );


	bSizer3->Add( 0, 0, 1, wxEXPAND, 5 );

	ConvertBtn = new wxButton( m_panel2, wxID_ANY, wxT("Convert"), wxDefaultPosition, wxDefaultSize, wxBU_LEFT );

	ConvertBtn->SetDefault();

	ConvertBtn->SetBitmap( convert_png_to_wx_bitmap() );
	ConvertBtn->SetBitmapPosition( wxLEFT );
	bSizer3->Add( ConvertBtn, 0, wxALL, 5 );


	m_panel2->SetSizer( bSizer3 );
	m_panel2->Layout();
	bSizer3->Fit( m_panel2 );
	MainSizer->Add( m_panel2, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( MainSizer, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

MainFrameBase::~MainFrameBase()
{
}

ItemPanelBase::ItemPanelBase( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer131;
	bSizer131 = new wxBoxSizer( wxHORIZONTAL );

	IconBitmap = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer131->Add( IconBitmap, 2, wxALL, 5 );


	bSizer131->Add( 0, 0, 5, wxEXPAND, 5 );

	TitleLabel = new wxStaticText( this, wxID_ANY, wxT("File Name"), wxDefaultPosition, wxDefaultSize, 0 );
	TitleLabel->Wrap( -1 );
	bSizer131->Add( TitleLabel, 1, wxALL|wxEXPAND, 5 );


	bSizer10->Add( bSizer131, 4, wxEXPAND, 5 );

	ProgressBar = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	ProgressBar->SetValue( 0 );
	bSizer10->Add( ProgressBar, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer10 );
	this->Layout();
}

ItemPanelBase::~ItemPanelBase()
{
}
