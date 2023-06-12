//
// Created by rhys on 07/06/23.
//

#include "MainFrame.h"

#define SCROLL_UNITS 10

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_COMMAND(wxID_ANY, CONVERSION_COMPLETE, MainFrame::OnConversionComplete)
    EVT_COMMAND(wxID_ANY, ITEM_CONVERSION_COMPLETE, MainFrame::OnItemConversionComplete)
wxEND_EVENT_TABLE()

MainFrame::MainFrame() :
    MainFrameBase(NULL, wxID_ANY, "Squoosher"),
    controller(),
    conversionQueue(ConvertingImagesScroller),
    totalConverted(0) {

    ConvertingImagesSizer->Add(&conversionQueue, 1, wxALL, 5);

    SetDropTarget(new FileDropTarget(this));
    CreateStatusBar();
}

void MainFrame::OnConvertImg(wxCommandEvent &event) {
    runConversion();
}

void MainFrame::runConversion() {
    ConvertBtn->Disable();
    int quality = QualityControl->GetValue();
    int width = WidthControl->GetValue();
    int height = HeightControl->GetValue();
    bool lossless = LosslessCheckbox->GetValue();

    for(ConversionElement& elem : conversionQueue.queue) {
        elem.quality = quality;
        elem.width = width;
        elem.height = height;
        elem.lossless = lossless;
    }

    GetStatusBar()->SetStatusText("Conversion in progress...");
    conversionQueue.beginConversion();
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

void MainFrame::loadImagePath(wxString path) {
    conversionQueue.addToQueue({
        .controller = new ImageController(path),
        .quality = 75,
        .width = 0,
        .height = 0,
        .lossless = 0
    });
}

void MainFrame::OnConversionComplete(wxCommandEvent &event) {
    conversionQueue.Reset();
    ConvertBtn->Enable();
    GetStatusBar()->SetStatusText(wxString::Format("Converted %d items", totalConverted));
}

void MainFrame::OnItemConversionComplete(wxCommandEvent &event) {
    totalConverted++;
}
