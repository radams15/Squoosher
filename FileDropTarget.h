//
// Created by rhys on 07/06/23.
//

#ifndef SQUOOSHER_FILEDROPTARGET_H
#define SQUOOSHER_FILEDROPTARGET_H

#include <wx/wx.h>
#include <wx/dnd.h>

class FileDropTarget : public wxFileDropTarget {
public:
    FileDropTarget(wxFrame* window);

    bool OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames) ;
private:
    wxFrame* window;
};


#endif //SQUOOSHER_FILEDROPTARGET_H
