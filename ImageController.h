//
// Created by rhys on 07/06/23.
//

#ifndef SQUOOSHER_IMAGECONTROLLER_H
#define SQUOOSHER_IMAGECONTROLLER_H

#include <wx/wx.h>

#include <webp/encode.h>

struct WebpData {
    unsigned char* data;
    unsigned int length;
};

class ImageController {
public:
    explicit ImageController(wxString inputFile);
    ~ImageController();

    void open(wxString file);

    wxBitmap encodeToBitmap(int width=-1, int height=-1);
    void encodeToFile(wxString fileName, int width=-1, int height=-1);
    inline void setQuality(int quality) { config.quality = quality; }
private:
    WebPConfig config;
    WebPPicture pic;

    struct WebpData encode(int width=-1, int height=-1);
    int loadImage(wxString fileName);
};


#endif //SQUOOSHER_IMAGECONTROLLER_H
