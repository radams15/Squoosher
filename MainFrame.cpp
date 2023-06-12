//
// Created by rhys on 07/06/23.
//

#include "MainFrame.h"

#define SCROLL_UNITS 10

MainFrame::MainFrame() :
    MainFrameBase(NULL, wxID_ANY, "Squoosher"),
    controller(),
    conversionQueue(this) {

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

    /*controller.setQuality(quality);

    wxImage img = controller.encodeToImage();
    if(width > 0 and height > 0) {
        int ratio = std::min(img.GetWidth()/width, img.GetHeight()/height);
        img.Rescale(img.GetWidth()/ratio, img.GetHeight()/ratio);
    }

    ImageScroller->SetScrollbars(img.GetWidth()/SCROLL_UNITS, img.GetHeight()/SCROLL_UNITS, SCROLL_UNITS, SCROLL_UNITS, 0, 0);

    DisplayImg->SetBitmap(img);*/
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

    //runConversion();
}
