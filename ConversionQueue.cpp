//
// Created by rhys on 08/06/23.
//

#include "ConversionQueue.h"
#include "ItemPanel.h"
#include "MainFrame.h"

#define Redraw() wxPostEvent(wxTheApp->GetTopWindow(), wxSizeEvent())

ConversionQueue::ConversionQueue(wxWindow *parent) :
        wxPanel(parent),
        queue(),
        thread(nullptr)
        {

    mainSizer = new wxBoxSizer(wxVERTICAL);

    SetSizer(mainSizer);
}

void ConversionQueue::beginConversion() {
    totalLength = queue.size();
    thread = new ConversionThread(this);
    thread->Run();
}


void ConversionQueue::addToQueue(ConversionElement element) {
    /*while(locked) {}
    locked = true;*/
    queue.push_back(element);
    //locked = false;

    auto* panel = new ItemPanel(
            this,
            element.webp->imageName
    );
    mainSizer->Add(panel, 1, wxALL, 5);

    Redraw();
}

ConversionElement& ConversionQueue::dequeue() {
    /*while(locked) {}
    locked = true;*/
    ConversionElement& elem = queue.back();
    queue.pop_back();
    //locked = false;

    wxSizerItem* item = mainSizer->GetChildren()[topElement];
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
    if(thread != nullptr) {
        if (thread->IsRunning())
            thread->Delete();
        delete thread;
    }

    thread = nullptr;
    queue.clear();
}

bool ConversionQueue::empty() {
    return topElement == mainSizer->GetChildren().size();
}

ConversionQueue::~ConversionQueue() {
    if(thread != nullptr) {
        if (thread->IsRunning())
            thread->Delete();
        delete thread;
    }

    thread = nullptr;
    queue.clear();
}
