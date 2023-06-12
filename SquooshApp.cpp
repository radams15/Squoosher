//
// Created by rhys on 07/06/23.
//

#include "SquooshApp.h"

#include "MainFrame.h"

bool SquooshApp::OnInit() {
    wxInitAllImageHandlers();

    auto* frame = new MainFrame();
    frame->Show();

    return true;
}
