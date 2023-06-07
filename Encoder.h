//
// Created by rhys on 07/06/23.
//
#ifndef ENCODER_H
#define ENCODER_H

#include <string>

#include <webp/encode.h>

int ReadImage(const char* filename, WebPPicture* const pic);
void img2webp(std::string in, std::string out);

#endif