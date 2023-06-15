//
// Created by rhys on 08/06/23.
//

#include "ConversionQueue.h"
#include "ItemPanel.h"
#include "MainFrame.h"

#define Redraw() wxPostEvent(wxTheApp->GetTopWindow(), wxSizeEvent())

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
            element.webp->imageName
    );
    mainSizer.Add(panel, 1, wxALL, 5);

    Redraw();
}

ConversionElement& ConversionQueue::dequeue() {
    ConversionElement& elem = queue.back();
    queue.pop_back();

    wxSizerItem* item = mainSizer.GetChildren()[topElement];
    auto* panel = (ItemPanel*) item->GetWindow();
    if(panel->GetId() != ID_ITEM_PANEL) {
        std::cerr << "Cannot identify item panel!\n";
        return elem;
    }
    panel->setComplete(true);
    Redraw();

    topElement++;

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

bool ConversionQueue::empty() {
    return topElement == mainSizer.GetChildren().size();
}
