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
    conversionQueue(ConvertingImagesScroller) {

    ConvertingImagesSizer->Add(&conversionQueue, 1, wxALL, 5);

    SetDropTarget(new FileDropTarget(this));
}

void MainFrame::OnConvertImg(wxCommandEvent &event) {
    runConversion();
}

void MainFrame::runConversion() {
    int quality = QualityControl->GetValue();
    int width = WidthControl->GetValue();
    int height = HeightControl->GetValue();

    std::for_each(conversionQueue.queue.begin(), conversionQueue.queue.end(), [quality, width, height](ConversionElement& elem) {
        elem.quality = quality;
        elem.width = width;
        elem.height = height;
    });

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
        int width = WidthControl->GetValue();
        int height = HeightControl->GetValue();

        controller.encodeToFile(dialog.GetPath(), width, height);
    }
}

void MainFrame::loadImagePath(wxString path) {
    conversionQueue.addToQueue({
        .controller = new ImageController(path),
        .quality = 75,
        .width = 0,
        .height = 0
    });
}

void MainFrame::OnConversionComplete(wxCommandEvent &event) {
    std::cout << "Conversion completed!!!!\n";
}

void MainFrame::OnItemConversionComplete(wxCommandEvent &event) {
    std::cout << "Item conversion completed!!!! (" << ((ConversionElement*)event.GetEventObject())->controller->imageName << ")\n";
    conversionQueue.dequeue();
}
