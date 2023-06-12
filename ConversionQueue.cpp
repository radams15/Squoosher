//
// Created by rhys on 08/06/23.
//

#include "ConversionQueue.h"
#include "ItemPanel.h"
#include "MainFrame.h"

wxDEFINE_EVENT(CONVERSION_COMPLETE, wxCommandEvent);
wxDEFINE_EVENT(ITEM_CONVERSION_COMPLETE, wxCommandEvent);

#define Redraw() wxPostEvent(wxTheApp->GetTopWindow(), wxSizeEvent());

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

    Redraw();
}

ConversionElement& ConversionQueue::dequeue() {
    ConversionElement& elem = queue.back();
    queue.pop_back();

    mainSizer.GetChildren().back()->Show(false);
    mainSizer.GetChildren().pop_back();
    Redraw();

    return elem;
}

void ConversionQueue::Reset() {
    thread->Kill();
    delete thread;

    thread = new ConversionThread(this);
    queue.clear();
}

ConversionThread::ConversionThread(ConversionQueue *parentQueue) :
    wxThread(wxTHREAD_JOINABLE),
    queue(parentQueue) {

}

wxThread::ExitCode ConversionThread::Entry() {
    while(! queue->queue.empty()) {
        ConversionElement& elem = queue->dequeue();

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
