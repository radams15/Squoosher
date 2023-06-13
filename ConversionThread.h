//
// Created by rhys on 13/06/23.
//

#ifndef SQUOOSHER_CONVERSIONTHREAD_H
#define SQUOOSHER_CONVERSIONTHREAD_H

#include <wx/wx.h>
#include "ImageController.h"


wxDECLARE_EVENT(CONVERSION_COMPLETE, wxCommandEvent);
wxDECLARE_EVENT(ITEM_CONVERSION_COMPLETE, wxCommandEvent);

struct ConversionElement {
    ImageController* controller;
    int quality, width, height;
    bool lossless;
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

#endif //SQUOOSHER_CONVERSIONTHREAD_H
