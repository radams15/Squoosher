//
// Created by rhys on 07/06/23.
//

#include "MainFrame.h"

#define SCROLL_UNITS 10

MainFrame::MainFrame() :
    MainFrameBase(NULL, wxID_ANY, "Squoosher"),
    controller() {

    SetDropTarget(new FileDropTarget(this));
}

void MainFrame::OnConvertImg(wxCommandEvent &event) {
    runConversion();
}

void MainFrame::runConversion() {
    int quality = QualityControl->GetValue();
    int width = WidthControl->GetValue();
    int height = HeightControl->GetValue();

    controller.setQuality(quality);

    wxBitmap bitmap = controller.encodeToBitmap(width, height);

    ImageScroller->SetScrollbars(bitmap.GetWidth()/SCROLL_UNITS, bitmap.GetHeight()/SCROLL_UNITS, SCROLL_UNITS, SCROLL_UNITS, 0, 0);

    DisplayImg->SetBitmap(bitmap);
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
        loadImagePath(dialog.GetPath());
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

void MainFrame::loadImagePath(wxString path) {
    controller.open(path);
    runConversion();
}
