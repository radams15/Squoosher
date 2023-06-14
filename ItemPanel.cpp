//
// Created by rhys on 08/06/23.
//

#include "ItemPanel.h"

#define ICON_SIZE 64

ItemPanel::ItemPanel(wxWindow *parent, wxString name) :
        ItemPanelBase(parent) {
    TitleLabel->SetLabel(name);
    ProgressBar->SetValue(0);

#ifdef IMAGE_PREVIEWS
    wxImage img(name);
    img.Rescale(ICON_SIZE, ICON_SIZE);
    IconBitmap->SetBitmap(wxBitmap(img));
#endif

    IconBitmap->Show(true);
}

void ItemPanel::setComplete(bool complete) {
    if(complete)
        ProgressBar->SetValue(100);
    else
        ProgressBar->SetValue(0);
}
