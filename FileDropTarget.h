//
// Created by rhys on 07/06/23.
//

#ifndef SQUOOSHER_FILEDROPTARGET_H
#define SQUOOSHER_FILEDROPTARGET_H

#include <wx/wx.h>
#include <wx/dnd.h>

wxDECLARE_EVENT(FILES_DROPPED, wxCommandEvent);

class FileDropTarget : public wxFileDropTarget {
public:
    explicit FileDropTarget();

    bool OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames) override;
private:
};


#endif //SQUOOSHER_FILEDROPTARGET_H
