//
// Created by Michal Ziobro on 02/10/2016.
//

#include <stdbool.h>
#include <stddef.h>

#ifndef COMMON_FUNCTIONS_PNG_DECODING_H
#define COMMON_FUNCTIONS_PNG_DECODING_H

extern bool isPNGFile(const char *filePath);
extern int readDataFromPNGFile(const char *filePath, unsigned char **data, size_t *dataLength, size_t *width, size_t *height, unsigned char *colorType, unsigned char *bitDepth);
extern int readRGBAFromPNGFile(const char *filePath, unsigned char **rgbaData, size_t *rgbaDataLength, size_t *width, size_t *height);

#endif //COMMON_FUNCTIONS_PNG_DECODING_H
