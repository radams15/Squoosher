//
// Created by rhys on 08/06/23.
//

#include "ConversionQueue.h"
#include "ItemPanel.h"
#include "MainFrame.h"

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
    auto* panel = new ItemPanel(
            this,
            element.controller->imageName
    );
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
    if(thread->IsRunning())
        thread->Kill();
    delete thread;

    thread = new ConversionThread(this);
    queue.clear();
}

ConversionQueue::~ConversionQueue() {
    if(thread->IsRunning())
        thread->Kill();
    delete thread;
}