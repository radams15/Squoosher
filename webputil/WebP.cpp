//
// Created by rhys on 07/06/23.
//

#include "WebP.h"

#include <imageio_util.h>
#include <wx/file.h>
#include <fstream>
#include <iostream>
#include "image_dec.h"

#define min(a, b) a<b? a : b

WebP::WebP() {

}

WebP::WebP(std::string file) {
    open(file);
}

void WebP::open(std::string file) {
    WebPConfigInit(&config);
    WebPPictureInit(&pic);

    if(loadImage(file) != 0)
        std::cerr << "Failed to load image!\n";

    imageName = file;
}

int WebPPictureRescaleKeepAR(WebPPicture* pic, int width, int height) {
    double ratio = min((double)pic->width/(double)width, (double)pic->height/(double)height);

    printf("Resize ratio is %f\n", ratio);

    return WebPPictureRescale(pic, (int) ((double)pic->width/ratio), (int) ((double)pic->height/ratio));
}

struct WebpData WebP::encode(int width, int height) {
    WebPMemoryWriter wrt;
    WebPPicture pictureCopy;

    if(pic.width == 0 or pic.height == 0) // No image is loaded.
        return {NULL, 0};

    //WebPPictureInit(&pictureCopy); // Possibly unneeded.
    WebPPictureCopy(&pic, &pictureCopy); // Deep copies the image data.

    // Only use use_argb if we really need it, as it's slower.
    pictureCopy.use_argb = config.lossless || config.use_sharp_yuv || config.preprocessing > 0;

    pictureCopy.writer = WebPMemoryWrite;
    pictureCopy.custom_ptr = &wrt;

    WebPMemoryWriterInit(&wrt);

    if(width > 0 and height > 0) {
        if (!WebPPictureRescaleKeepAR(&pictureCopy, width, height)) {
            std::cerr << "Cannot rescale image!\n";
        }
    }

    WebPEncode(&config, &pictureCopy);
    WebPPictureFree(&pictureCopy);

    return {
        wrt.mem,
        (unsigned int) wrt.size
    };
}

int WebP::loadImage(std::string fileName) {
    const uint8_t* data = NULL;
    size_t data_size = 0;
    WebPImageReader reader;

    int ok;
    if (!ImgIoUtilReadFile(fileName.c_str(), &data, &data_size))
        return 0;

    reader = WebPGuessImageReader(data, data_size);
    ok = reader(data, data_size, &pic, 1, NULL);

    //free((void*)data);
    return ok != 1;
}

void WebP::encodeToFile(std::string fileName, int width, int height) {
    struct WebpData data = encode(width, height);

    std::ofstream of(fileName);

    of.write((const char*) data.data, data.length);

    of.close();
}

WebP::~WebP() {
    //WebPPictureFree(&pic);
}

void WebP::setQuality(int quality) {
    config.quality = (float) quality;
}

void WebP::setLossless(bool lossless) {
    config.lossless = lossless;
}
