//
// Created by rhys on 08/06/23.
//

#include "ItemPanel.h"

ItemPanel::ItemPanel(wxWindow *parent, wxString name) :
        ItemPanelBase(parent, wxID_ANY) {
    TitleLabel->SetLabel(name);
    DoneLabel->SetLabel("Queued");
}
