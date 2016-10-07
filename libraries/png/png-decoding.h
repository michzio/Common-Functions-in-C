//
// Created by Michal Ziobro on 02/10/2016.
//

#include <stdbool.h>
#include <stddef.h>

#ifndef COMMON_FUNCTIONS_PNG_DECODING_H
#define COMMON_FUNCTIONS_PNG_DECODING_H

#define PNG_BIT_DEPTH_1 1
#define PNG_BIT_DEPTH_2 2
#define PNG_BIT_DEPTH_4 4
#define PNG_BIT_DEPTH_8 8
#define PNG_BIT_DEPTH_16 16

extern bool isPNGFile(const char *filePath);

// reading from PNG file
extern int readDataFromPNGFile(const char *filePath, unsigned char **data, size_t *dataLength, size_t *width, size_t *height, unsigned char *bitDepth, unsigned char *colorType);
extern int readRGBAfromPNGFile(const char *filePath, unsigned char **rgbaData, size_t *rgbaDataLength, size_t *width, size_t *height, unsigned char *bitDepth);
extern int readRGBfromPNGFile(const char *filePath, unsigned char **rgbData, size_t *rgbDataLength, size_t *width, size_t *height, unsigned char *bitDepth);
extern int readGrayscaleAlphaFromPNGFile(const char *filePath, unsigned char **gaData, size_t *gaDataLength, size_t *width, size_t *height, unsigned char *bitDepth);
extern int readGrayscaleFromPNGFile(const char *filePath, unsigned char **gData, size_t *gDataLength, size_t *width, size_t *height, unsigned char *bitDepth);

// reading from PNG buffer
extern int readDataFromPNGBuffer(const unsigned char *pngData, const size_t pngDataLength, unsigned char **data, size_t *dataLength, size_t *width, size_t *height, unsigned char *bitDepth, unsigned char *colorType);
extern int readRGBAfromPNGBuffer(const unsigned char *pngData, const size_t pngDataLength, unsigned char **rgbaData, size_t *rgbaDataLength, size_t *width, size_t *height, unsigned char *bitDepth);
extern int readRGBfromPNGBuffer(const unsigned char *pngData, const size_t pngDataLength, unsigned char **rgbData, size_t *rgbDataLength, size_t *width, size_t *height, unsigned char *bitDepth);
extern int readGrayscaleAlphaFromPNGBuffer(const unsigned char *pngData, const size_t pngDataLength, unsigned char **gaData, size_t *gaDataLength, size_t *width, size_t *height, unsigned char *bitDepth);
extern int readGrayscaleFromPNGBuffer(const unsigned char *pngData, const size_t pngDataLength, unsigned char **gData, size_t *gDataLength, size_t *width, size_t *height, unsigned char *bitDepth);

#endif //COMMON_FUNCTIONS_PNG_DECODING_H
