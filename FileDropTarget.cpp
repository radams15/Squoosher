//
// Created by rhys on 07/06/23.
//

#include "FileDropTarget.h"
#include "MainFrame.h"

wxDEFINE_EVENT(FILES_DROPPED, wxCommandEvent);

FileDropTarget::FileDropTarget() : wxFileDropTarget() {

}

bool FileDropTarget::OnDropFiles(wxCoord x, wxCoord y, const wxArrayString &filenames) {
    for(const wxString& file : filenames) {
        wxCommandEvent evt(FILES_DROPPED, wxID_ANY);
        evt.SetString(file);
        wxPostEvent(wxTheApp->GetTopWindow(), evt);
    }

    return true;
}
