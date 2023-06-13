//
// Created by rhys on 13/06/23.
//

#include "ConversionThread.h"
#include "ConversionQueue.h"

wxDEFINE_EVENT(CONVERSION_COMPLETE, wxCommandEvent);
wxDEFINE_EVENT(ITEM_CONVERSION_COMPLETE, wxCommandEvent);


ConversionThread::ConversionThread(ConversionQueue *parentQueue) :
        wxThread(wxTHREAD_JOINABLE),
        queue(parentQueue) {

}

wxThread::ExitCode ConversionThread::Entry() {
    while(! queue->queue.empty()) {
        ConversionElement& elem = queue->dequeue();

        wxString newName = elem.controller->imageName + ".webp";
        elem.controller->setQuality(elem.quality);
        elem.controller->setLossless(elem.lossless);

        elem.controller->encodeToFile(newName, elem.width, elem.height);

        wxCommandEvent evt(ITEM_CONVERSION_COMPLETE, wxID_ANY);
        evt.SetEventObject((wxObject*) &elem);
        wxPostEvent(wxTheApp->GetTopWindow(), evt);

        if(TestDestroy())
            break;
    }

    wxCommandEvent evt(CONVERSION_COMPLETE, wxID_ANY);
    wxPostEvent(wxTheApp->GetTopWindow(), evt);

    return (ExitCode) EXIT_SUCCESS;
}

ConversionThread::~ConversionThread() {
    if(IsRunning())
        Kill();
}
