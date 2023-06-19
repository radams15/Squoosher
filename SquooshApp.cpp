//
// Created by rhys on 07/06/23.
//

#include "SquooshApp.h"

#include "MainFrame.h"
#include <wx/sysopt.h>

bool SquooshApp::OnInit() {
    wxInitAllImageHandlers();

#ifdef __WXMAC__
    SetExitOnFrameDelete(false);
    wxSystemOptions::SetOption( wxMAC_WINDOW_PLAIN_TRANSITION, 0 );
#endif

    auto* frame = new MainFrame();
    frame->Show();

    return true;
}
