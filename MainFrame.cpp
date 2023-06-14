//
// Created by rhys on 07/06/23.
//

#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_COMMAND(wxID_ANY, CONVERSION_COMPLETE, MainFrame::OnConversionComplete)
    EVT_COMMAND(wxID_ANY, ITEM_CONVERSION_COMPLETE, MainFrame::OnItemConversionComplete)
    EVT_COMMAND(wxID_ANY, FILES_DROPPED, MainFrame::OnImageDropped)
wxEND_EVENT_TABLE()

MainFrame::MainFrame() :
    MainFrameBase(NULL, wxID_ANY, _T("Squoosher")),
    webP(),
    conversionQueue(ConvertingImagesScroller) {

    ConvertingImagesSizer->Add(&conversionQueue, 1, wxALL, 5);

    SetDropTarget(new FileDropTarget());
    CreateStatusBar();
}

void MainFrame::OnConvertImg(wxCommandEvent &event) {
    runConversion();
}

void MainFrame::runConversion() {
    ConvertBtn->Disable();
    int quality = QualitySlider->GetValue();
    int width = WidthControl->GetValue();
    int height = HeightControl->GetValue();

    bool lossless = LosslessCheckbox->GetValue();

    for(ConversionElement& elem : conversionQueue.queue) {
        elem.quality = quality;
        elem.width = width;
        elem.height = height;
        elem.lossless = lossless;
    }

    GetStatusBar()->SetStatusText(_T("Conversion in progress..."));
    conversionQueue.beginConversion();
}

void MainFrame::OnImageOpen(wxCommandEvent &event) {
    wxFileDialog dialog(
            this,
            _T("Open File"),
            wxEmptyString,
            wxEmptyString,
            _T("Image files (*.jpg;*.JPG;*.jpeg;*.png;*.tiff)"),
            wxFD_OPEN|wxFD_FILE_MUST_EXIST
    );

    if (dialog.ShowModal() == wxID_OK) {
        loadImagePath(dialog.GetPath());
    }
}

void MainFrame::loadImagePath(wxString path) {
    conversionQueue.addToQueue(ConversionElement{
        .webp = new WebP(path.ToStdString()),
        .quality = 75,
        .width = 0,
        .height = 0,
        .lossless = false,
    });
}

void MainFrame::OnImageDropped(wxCommandEvent &event) {
    loadImagePath(event.GetString());
}

void MainFrame::OnConversionComplete(wxCommandEvent &event) {
    conversionQueue.Reset();
    ConvertBtn->Enable();
    GetStatusBar()->SetStatusText(wxString::Format(_T("Converted %d items"), totalConverted));
}

void MainFrame::OnItemConversionComplete(wxCommandEvent &event) {
    totalConverted++;
}

MainFrame::~MainFrame() {
    conversionQueue.Reset();
}

void MainFrame::OnQualityChanged(wxScrollEvent &event) {
    if(QualitySlider->GetValue() == 100)
        LosslessCheckbox->SetValue(true);
    else
        LosslessCheckbox->SetValue(false);
}
