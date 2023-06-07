//
// Created by rhys on 07/06/23.
//

#include "MainFrame.h"

MainFrame::MainFrame() :
    MainFrameBase(NULL, wxID_ANY, "Squoosher"),
    controller("/home/rhys/scripts/squoosher/in.jpg") {

}

void MainFrame::OnConvertImg(wxCommandEvent &event) {
    runConversion();
}

void MainFrame::runConversion() {
    int quality = QualityControl->GetValue();

    controller.setQuality(quality);

    DisplayImg->SetBitmap(controller.encodeToBitmap());
}

void MainFrame::OnImageOpen(wxCommandEvent &event) {
    wxFileDialog dialog(
            this,
            _T("Open File"),
            wxEmptyString,
            wxEmptyString,
            _T("image files (*.jpg;*.JPG;*.jpeg;*.png;*.tiff)"),
            wxFD_OPEN|wxFD_FILE_MUST_EXIST
    );

    if (dialog.ShowModal() == wxID_OK) {
        controller.open(dialog.GetPath());
        runConversion();
    }
}

void MainFrame::OnImageSave(wxCommandEvent &event) {
    wxFileDialog dialog(
          this,
        _T("Save webp file"),
        wxEmptyString,
        wxEmptyString,
        _T("WEBP files (*.webp)"),
           wxFD_SAVE|wxFD_OVERWRITE_PROMPT
    );

    if (dialog.ShowModal() == wxID_OK) {
        controller.encodeToFile(dialog.GetPath());
    }
}
