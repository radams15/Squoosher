//
// Created by rhys on 07/06/23.
//

#ifndef SQUOOSHER_WEBP_H
#define SQUOOSHER_WEBP_H

#include <string>

#include <webp/encode.h>

struct WebpData {
    unsigned char* data;
    unsigned int length;
};

class WebP {
public:
    WebP();
    explicit WebP(std::string file);
    ~WebP();

    void open(std::string file);

    std::string imageName;

    void encodeToFile(std::string fileName, int width=-1, int height=-1);
    void setQuality(int quality);
    void setLossless(bool lossless);
private:
    WebPConfig config;
    WebPPicture pic;

    struct WebpData encode(int width=-1, int height=-1);
    int loadImage(std::string fileName);
};


#endif //SQUOOSHER_WEBP_H
