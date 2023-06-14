//
// Created by rhys on 07/06/23.
//

#ifndef SQUOOSHER_MAINFRAME_H
#define SQUOOSHER_MAINFRAME_H

#include <wx/wx.h>

#include "Squoosh.h"
#include <WebP.h>
#include "FileDropTarget.h"
#include "ConversionQueue.h"

class MainFrame : public MainFrameBase {
public:
    MainFrame();
    ~MainFrame() override;

    void loadImagePath(wxString path);

protected:
    void OnConvertImg( wxCommandEvent& event ) override;
    void OnImageOpen( wxCommandEvent& event ) override;
    void OnQualityChanged( wxScrollEvent& event ) override;
private:
    WebP webP;
    ConversionQueue conversionQueue;
    int totalConverted = 0;

    void runConversion();

    void OnConversionComplete(wxCommandEvent& event);
    void OnItemConversionComplete(wxCommandEvent& event);
    void OnImageDropped( wxCommandEvent& event );

wxDECLARE_EVENT_TABLE();
};


#endif //SQUOOSHER_MAINFRAME_H
