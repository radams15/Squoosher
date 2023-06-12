//
// Created by rhys on 08/06/23.
//

#include "ItemPanel.h"

#define ICON_SIZE 64

ItemPanel::ItemPanel(wxWindow *parent, wxString name) :
        ItemPanelBase(parent, wxID_ANY) {
    TitleLabel->SetLabel(name);
    DoneLabel->SetLabel("Queued");

#ifdef IMAGE_PREVIEWS
    wxImage img(name);
    img.Rescale(ICON_SIZE, ICON_SIZE);
    IconBitmap->SetBitmap(wxBitmap(img));
#endif

    IconBitmap->Show(true);
}
