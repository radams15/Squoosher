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

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	ImageScroller = new wxScrolledWindow( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	ImageScroller->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	DisplayImg = new wxStaticBitmap( ImageScroller, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( DisplayImg, 1, wxALL, 5 );


	ImageScroller->SetSizer( bSizer7 );
	ImageScroller->Layout();
	bSizer7->Fit( ImageScroller );
	bSizer2->Add( ImageScroller, 1, wxEXPAND | wxALL, 5 );


	m_panel1->SetSizer( bSizer2 );
	m_panel1->Layout();
	bSizer2->Fit( m_panel1 );
	bSizer6->Add( m_panel1, 4, wxEXPAND | wxALL, 5 );

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

	ConvertBtn = new wxButton( m_panel2, wxID_ANY, wxT("Convert"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( ConvertBtn, 0, wxALL, 5 );

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText11 = new wxStaticText( m_panel2, wxID_ANY, wxT("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer41->Add( m_staticText11, 0, wxALL, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	WidthControl = new wxSpinCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000000, -1 );
	bSizer11->Add( WidthControl, 0, wxALL, 5 );

	HeightControl = new wxSpinCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000000, 0 );
	bSizer11->Add( HeightControl, 0, wxALL, 5 );


	bSizer41->Add( bSizer11, 1, wxEXPAND, 5 );


	bSizer3->Add( bSizer41, 1, wxEXPAND, 5 );


	m_panel2->SetSizer( bSizer3 );
	m_panel2->Layout();
	bSizer3->Fit( m_panel2 );
	bSizer6->Add( m_panel2, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer6, 1, wxEXPAND, 5 );


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
