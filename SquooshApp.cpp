//
// Created by rhys on 07/06/23.
//

#include "SquooshApp.h"

#include "MainFrame.h"

bool SquooshApp::OnInit() {
    MainFrame* frame = new MainFrame();
    frame->Show();

    return true;
}
