//
// Created by rhys on 08/06/23.
//

#ifndef SQUOOSHER_CONVERSIONQUEUE_H
#define SQUOOSHER_CONVERSIONQUEUE_H

#include <queue>

#include <wx/wx.h>

#include "ConversionThread.h"

class ConversionQueue : public wxPanel {
friend ConversionThread;
public:
    explicit ConversionQueue(wxWindow* parent);
    ~ConversionQueue();
    void Reset();

    void beginConversion();
    void addToQueue(ConversionElement element);
    bool empty();

    ConversionElement& dequeue();

    std::vector<ConversionElement> queue;
    int totalLength;
private:
    //bool locked = false;
    int topElement = 0;
    ConversionThread* thread;
    wxBoxSizer* mainSizer;
};


#endif //SQUOOSHER_CONVERSIONQUEUE_H
