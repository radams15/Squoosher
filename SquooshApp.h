//
// Created by rhys on 07/06/23.
//

#ifndef SQUOOSHER_SQUOOSHAPP_H
#define SQUOOSHER_SQUOOSHAPP_H

#include <wx/wx.h>

class SquooshApp : public wxApp {
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(SquooshApp);


#endif //SQUOOSHER_SQUOOSHAPP_H
