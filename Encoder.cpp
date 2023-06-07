//
// Created by rhys on 07/06/23.
//
#include "Encoder.h"

#include <fstream>

#include <webp/encode.h>
#include <imageio_util.h>
#include "image_dec.h"

int ReadImage(const char* filename, WebPPicture* const pic) {
    const uint8_t* data = NULL;
    size_t data_size = 0;
    WebPImageReader reader;

    int ok;
    if (!ImgIoUtilReadFile(filename, &data, &data_size))
        return 0;

    reader = WebPGuessImageReader(data, data_size);
    ok = reader(data, data_size, pic, 1, NULL);

    WebPFree((void*)data);
    return ok;
}

void save(unsigned char* data, int length, const std::string& filename) {
    std::ofstream os(filename);

    os.write((const char*) data, length);

    os.close();
}

unsigned char* encode(WebPPicture* pic, int width, int height, WebPConfig config) {
    WebPMemoryWriter wrt;

    // Allow quality to go higher than 0.
    config.qmax = 100;

    // Only use use_argb if we really need it, as it's slower.
    pic->use_argb = config.lossless || config.use_sharp_yuv || config.preprocessing > 0;

    if(width != -1)
        pic->width = width;
    if(height != -1)
        pic->height = height;

    pic->writer = WebPMemoryWrite;
    pic->custom_ptr = &wrt;

    WebPMemoryWriterInit(&wrt);

    WebPEncode(&config, pic);

    WebPPictureFree(pic);

    save(wrt.mem, wrt.size, "out.webp");
    // wrt.size, wrt.mem
    WebPMemoryWriterClear(&wrt);

    return wrt.mem;
}

void img2webp(std::string in, std::string out) {
    WebPConfig config;
    WebPConfigInit(&config);

    WebPPicture pic;
    WebPPictureInit(&pic);

    int ok = ReadImage(in.c_str(), &pic);
    if(!ok)
        fprintf(stderr, "Image load error!\n");

    encode(&pic, -1, -1, config);
}