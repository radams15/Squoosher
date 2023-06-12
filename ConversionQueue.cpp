//
// Created by rhys on 08/06/23.
//

#include "ConversionQueue.h"
#include "ItemPanel.h"
#include "MainFrame.h"

wxDEFINE_EVENT(CONVERSION_COMPLETE, wxCommandEvent);
wxDEFINE_EVENT(ITEM_CONVERSION_COMPLETE, wxCommandEvent);

ConversionQueue::ConversionQueue(wxWindow *parent) :
        wxPanel(parent),
        mainSizer(wxVERTICAL),
        queue() {

    SetSizer(&mainSizer);

    thread = new ConversionThread(this);
}

void ConversionQueue::beginConversion() {
    thread->Run();
}


void ConversionQueue::addToQueue(ConversionElement element) {
    queue.push_back(element);
    ItemPanel* panel = new ItemPanel(this, element.controller->imageName);
    mainSizer.Add(panel, 1, wxALL, 5);

    wxPostEvent(wxTheApp->GetTopWindow(), wxSizeEvent());
}

void ConversionQueue::dequeue() {
    queue.pop_back();
    mainSizer.GetChildren().back()->Show(false);
    delete mainSizer.GetChildren().back();
    mainSizer.GetChildren().pop_back();
    mainSizer.Layout();
}

ConversionThread::ConversionThread(ConversionQueue *parentQueue) :
    wxThread(wxTHREAD_JOINABLE),
    queue(parentQueue) {

}

wxThread::ExitCode ConversionThread::Entry() {
    for(const ConversionElement& elem : queue->queue) {
        wxString newName = elem.controller->imageName + ".webp";
        elem.controller->setQuality(elem.quality);
        elem.controller->encodeToFile(newName, elem.width, elem.height);

        wxCommandEvent evt(ITEM_CONVERSION_COMPLETE, wxID_ANY);
        evt.SetEventObject((wxObject*) &elem);
        wxPostEvent(wxTheApp->GetTopWindow(), evt);

        if(TestDestroy())
            break;
    }

    wxCommandEvent evt(CONVERSION_COMPLETE, wxID_ANY);
    wxPostEvent(wxTheApp->GetTopWindow(), evt);

    return (ExitCode) 0;
}

ConversionThread::~ConversionThread() {

}
