///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Squoosh.h"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Open") ) + wxT('\t') + wxT("ctrl-o"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItem1->SetBitmaps( wxNullBitmap );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_menuItem1->SetBitmap( wxNullBitmap );
	#endif
	m_menu1->Append( m_menuItem1 );

	wxMenuItem* m_menuItem2;
	m_menuItem2 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Save") ) + wxT('\t') + wxT("ctrl-s"), wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem2 );

	m_menubar1->Append( m_menu1, wxT("File") );

	this->SetMenuBar( m_menubar1 );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxHORIZONTAL );

	ConvertingImagesScroller = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
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

	QualityControl = new wxSpinCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 100, 75 );
	bSizer4->Add( QualityControl, 0, wxALL, 5 );


	bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText11 = new wxStaticText( m_panel2, wxID_ANY, wxT("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer41->Add( m_staticText11, 0, wxALL, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5 = new wxStaticText( m_panel2, wxID_ANY, wxT("Width"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer9->Add( m_staticText5, 0, wxALL, 5 );

	WidthControl = new wxSpinCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000000, -1 );
	bSizer9->Add( WidthControl, 0, wxALL, 5 );


	bSizer11->Add( bSizer9, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText6 = new wxStaticText( m_panel2, wxID_ANY, wxT("Height"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer91->Add( m_staticText6, 0, wxALL, 5 );

	HeightControl = new wxSpinCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000000, 0 );
	bSizer91->Add( HeightControl, 0, wxALL, 5 );


	bSizer11->Add( bSizer91, 1, wxEXPAND, 5 );


	bSizer41->Add( bSizer11, 1, wxEXPAND, 5 );


	bSizer3->Add( bSizer41, 1, wxEXPAND, 5 );

	ConvertBtn = new wxButton( m_panel2, wxID_ANY, wxT("Convert"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( ConvertBtn, 0, wxALL, 5 );


	m_panel2->SetSizer( bSizer3 );
	m_panel2->Layout();
	bSizer3->Fit( m_panel2 );
	MainSizer->Add( m_panel2, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( MainSizer, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnImageOpen ), this, m_menuItem1->GetId());
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnImageSave ), this, m_menuItem2->GetId());
	ConvertBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnConvertImg ), NULL, this );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	ConvertBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnConvertImg ), NULL, this );

}

ItemPanelBase::ItemPanelBase( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	TitleLabel = new wxStaticText( this, wxID_ANY, wxT("File Name"), wxDefaultPosition, wxDefaultSize, 0 );
	TitleLabel->Wrap( -1 );
	bSizer10->Add( TitleLabel, 1, wxALL, 5 );

	DoneLabel = new wxStaticText( this, wxID_ANY, wxT("Incomplete"), wxDefaultPosition, wxDefaultSize, 0 );
	DoneLabel->Wrap( -1 );
	bSizer10->Add( DoneLabel, 1, wxALL, 5 );


	this->SetSizer( bSizer10 );
	this->Layout();
}

ItemPanelBase::~ItemPanelBase()
{
}
