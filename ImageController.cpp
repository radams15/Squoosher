//
// Created by rhys on 07/06/23.
//

#include "ImageController.h"

#include <imageio_util.h>
#include <wx/file.h>
#include "image_dec.h"

ImageController::ImageController(wxString inputFile) {

}

void ImageController::open(wxString file) {
    WebPConfigInit(&config);
    WebPPictureInit(&pic);

    // Allow quality to go higher than 0.
    config.qmax = 100;

    config.lossless = 0;

    if(loadImage(file) != 0)
        std::cerr << "Failed to load image!\n";
}


struct WebpData ImageController::encode(int width, int height) {
    WebPMemoryWriter wrt;

    if(pic.width == 0 or pic.height == 0) // No image is loaded
        return {NULL, 0};

    // Only use use_argb if we really need it, as it's slower.
    pic.use_argb = config.lossless || config.use_sharp_yuv || config.preprocessing > 0;

    if(width != -1)
        pic.width = width;
    if(height != -1)
        pic.height = height;

    pic.writer = WebPMemoryWrite;
    pic.custom_ptr = &wrt;

    WebPMemoryWriterInit(&wrt);

    WebPEncode(&config, &pic);

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

wxBitmap ImageController::encodeToBitmap(int width, int height) {
    wxImage out;

    struct WebpData data = encode(width, height);

    if(data.length == 0)
        return wxBitmap{};

    uint8_t* rgb = WebPDecodeRGB(data.data, data.length, &pic.width, &pic.height);

    out.Create(pic.width, pic.height, rgb, false);
    out.SetMask(false);

    return wxBitmap{out};
}

void ImageController::encodeToFile(wxString fileName, int width, int height) {
    struct WebpData data = encode(width, height);

    wxFile os(fileName, wxFile::read_write);

    os.Write(data.data, data.length);

    os.Close();
}

ImageController::~ImageController() {
    WebPPictureFree(&pic);
}
