//
// Created by rhys on 08/06/23.
//

#ifndef SQUOOSHER_CONVERSIONQUEUE_H
#define SQUOOSHER_CONVERSIONQUEUE_H

#include <queue>

#include <wx/wx.h>

#include "ImageController.h"
#include "ConversionThread.h"

class ConversionQueue : public wxPanel {
friend ConversionThread;
public:
    explicit ConversionQueue(wxWindow* parent);
    ~ConversionQueue();
    void Reset();

    void beginConversion();
    void addToQueue(ConversionElement element);

    ConversionElement& dequeue();

    std::vector<ConversionElement> queue;
private:
    ConversionThread* thread;
    wxBoxSizer mainSizer;
};


#endif //SQUOOSHER_CONVERSIONQUEUE_H
