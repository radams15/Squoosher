//
// Created by rhys on 07/06/23.
//

#ifndef SQUOOSHER_MAINFRAME_H
#define SQUOOSHER_MAINFRAME_H

#include <wx/wx.h>

#include "Squoosh.h"
#include "ImageController.h"
#include "FileDropTarget.h"
#include "ConversionQueue.h"

class MainFrame : public MainFrameBase {
public:
    MainFrame();

    void loadImagePath(wxString path);

protected:
    void OnConvertImg( wxCommandEvent& event );
    void OnImageOpen( wxCommandEvent& event );
    void OnImageSave( wxCommandEvent& event );
private:
    ImageController controller;
    ConversionQueue conversionQueue;
    void runConversion();
};


#endif //SQUOOSHER_MAINFRAME_H
