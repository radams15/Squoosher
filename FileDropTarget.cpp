//
// Created by rhys on 07/06/23.
//

#include "FileDropTarget.h"
#include "MainFrame.h"

FileDropTarget::FileDropTarget(wxFrame* window) : wxFileDropTarget(), window(window) {

}

bool FileDropTarget::OnDropFiles(wxCoord x, wxCoord y, const wxArrayString &filenames) {
    if(filenames.size() > 0)
        ((MainFrame*)window)->loadImagePath(filenames.Item(0));

    return true;
}
