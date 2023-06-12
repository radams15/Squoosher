//
// Created by rhys on 08/06/23.
//

#ifndef SQUOOSHER_CONVERSIONQUEUE_H
#define SQUOOSHER_CONVERSIONQUEUE_H

#include <queue>

#include <wx/wx.h>

#include "ImageController.h"

struct ConversionElement {
    ImageController* controller;
    int quality, width, height;
};

class ConversionQueue;

class ConversionThread : public wxThread {
public:
    explicit ConversionThread(ConversionQueue* parentQueue);
    ~ConversionThread();
protected:
    ExitCode Entry() override;
private:
    ConversionQueue* queue;
};

class ConversionQueue : public wxPanel {
friend ConversionThread;
public:
    explicit ConversionQueue(wxWindow* parent);

    void beginConversion();
    void addToQueue(ConversionElement element);

    std::vector<ConversionElement> queue;
private:
    ConversionThread* thread;
    wxBoxSizer mainSizer;
};


#endif //SQUOOSHER_CONVERSIONQUEUE_H
