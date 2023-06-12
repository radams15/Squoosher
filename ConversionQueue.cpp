//
// Created by rhys on 08/06/23.
//

#include "ConversionQueue.h"
#include "ItemPanel.h"

ConversionQueue::ConversionQueue(wxWindow *parent) :
        wxPanel(parent),
        mainSizer(wxVERTICAL),
        queue() {

    SetSizer(&mainSizer);

    thread = new ConversionThread(this);
}

void ConversionQueue::beginConversion() {
    thread->Run();
    thread->Kill();
}


void ConversionQueue::addToQueue(ConversionElement element) {
    queue.push_back(element);
    ItemPanel* panel = new ItemPanel(this, element.controller->imageName);
    mainSizer.Add(panel);
}

ConversionThread::ConversionThread(ConversionQueue *parentQueue) :
    wxThread(wxTHREAD_DETACHED),
    queue(parentQueue) {

}

wxThread::ExitCode ConversionThread::Entry() {
    while(!TestDestroy()) {
        for(auto elem : queue->queue) {
            wxString newName = elem.controller->imageName + ".webp";
            elem.controller->setQuality(elem.quality);

            //std::printf("Converting '%s' to '%s'\n", (const char*) elem.controller->imageName.c_str(), (const char*) newName.c_str());

            elem.controller->encodeToFile(newName, elem.width, elem.height);
        }

        goto done;
    }

done:

    return (ExitCode) malloc(1);
}

ConversionThread::~ConversionThread() {

}
