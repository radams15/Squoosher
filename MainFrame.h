//
// Created by rhys on 07/06/23.
//

#ifndef SQUOOSHER_MAINFRAME_H
#define SQUOOSHER_MAINFRAME_H

#include "Squoosh.h"
#include "ImageController.h"
#include <wx/wx.h>

class MainFrame : public MainFrameBase {
public:
    MainFrame();

protected:
    void OnConvertImg( wxCommandEvent& event );
    void OnImageOpen( wxCommandEvent& event );
    void OnImageSave( wxCommandEvent& event );
private:
    ImageController controller;
    void runConversion();
};


#endif //SQUOOSHER_MAINFRAME_H
