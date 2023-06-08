//
// Created by rhys on 07/06/23.
//

#include "ImageController.h"

#include <imageio_util.h>
#include <wx/file.h>
#include <fstream>
#include "image_dec.h"

ImageController::ImageController() {

}

void ImageController::open(wxString file) {
    WebPConfigInit(&config);
    WebPPictureInit(&pic);

    // Allow quality to go higher than 0.
    config.qmax = 100;
    config.method = 6;
    config.lossless = 0;

    if(loadImage(file) != 0)
        std::cerr << "Failed to load image!\n";
}

int WebPPictureRescaleKeepAR(WebPPicture* pic, int width, int height) {
    int ratio = std::min(pic->width/width, pic->height/height);

    return WebPPictureRescale(pic, pic->width/ratio, pic->height/ratio);
}

/*int WebPPictureDup(WebPPicture* src, WebPPicture* dst) {
    uint8_t* rgb = WebPDecodeRGB(data.data, data.length, &pic.width, &pic.height);
    WebPEncodeRGB()
}*/

struct WebpData ImageController::encode(int width, int height) {
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

int ImageController::loadImage(wxString fileName) {
    const uint8_t* data = NULL;
    size_t data_size = 0;
    WebPImageReader reader;

    int ok;
    if (!ImgIoUtilReadFile(fileName.c_str(), &data, &data_size))
        return 0;

    reader = WebPGuessImageReader(data, data_size);
    ok = reader(data, data_size, &pic, 1, NULL);

    WebPFree((void*)data);
    return ok != 1;
}

wxImage ImageController::encodeToImage(int width, int height) {
    wxImage out;

    struct WebpData data = encode(width, height);

    std::printf("Image %d bytes\n", data.length);

    if(data.length == 0)
        return wxImage{};

    uint8_t* rgb = WebPDecodeRGB(data.data, data.length, &pic.width, &pic.height);

    out.Create(pic.width, pic.height, rgb, false);
    out.SetMask(false);

    return out;
}

void ImageController::encodeToFile(wxString fileName, int width, int height) {
    struct WebpData data = encode(width, height);

    std::ofstream of(fileName.ToStdString());

    of.write((const char*) data.data, data.length);

    of.close();
}

ImageController::~ImageController() {
    WebPPictureFree(&pic);
}

void ImageController::setQuality(int quality) {
    config.quality = (float) quality;
}
