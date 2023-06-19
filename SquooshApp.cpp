//
// Created by rhys on 07/06/23.
//

#include "SquooshApp.h"

#include "MainFrame.h"

bool SquooshApp::OnInit() {
    wxInitAllImageHandlers();

#ifdef __WXMAC__
    SetExitOnFrameDelete(false);
#endif

    auto* frame = new MainFrame();
    frame->Show();

    return true;
}
