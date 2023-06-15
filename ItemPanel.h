//
// Created by rhys on 08/06/23.
//

#ifndef SQUOOSHER_ITEMPANEL_H
#define SQUOOSHER_ITEMPANEL_H


#include "Squoosh.h"

class ItemPanel : public ItemPanelBase {
public:
    ItemPanel(wxWindow* parent, const wxString& name);
    void setComplete(bool complete);
private:

};


#endif //SQUOOSHER_ITEMPANEL_H
