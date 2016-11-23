//
// Created by Michal Ziobro on 30/09/2016.
//

#ifndef COMMON_FUNCTIONS_PNG_H
#define COMMON_FUNCTIONS_PNG_H

#include <stdio.h>

// writing to PNG file
extern int writeDataAsPNGFile(const unsigned char *data, const size_t width, const size_t height, const int bitDepth, const int colorType, const char *filePath);
extern int writeRGBAasPNGFile(const unsigned char *rgbaData, const size_t width, const size_t height, const int bitDepth, const char *filePath);
extern int writeRGBasPNGFile(const unsigned char *rgbData, const size_t width, const size_t height, const int bitDepth, const char *filePath);
extern int writeGrayscaleAlphaAsPNGFile(const unsigned char *gaData, const size_t width, const size_t height, const int bitDepth, const char *filePath);
extern int writeGrayscaleAsPNGFile(const unsigned char *gData, const size_t width, const size_t height, const int bitDepth, const char *filePath);

// writing to PNG buffer
extern int writeDataIntoPNGBuffer(const unsigned char *data, const size_t width, const size_t height, const int bitDepth, const int colorType, unsigned char **pngData, size_t *pngDataLength);
extern int writeRGBAintoPNGBuffer(const unsigned char *rgbaData, const size_t width, const size_t height, const int bitDepth, unsigned char **pngData, size_t *pngDataLength);
extern int writeRGBintoPNGBuffer(const unsigned char *rgbData, const size_t width, const size_t height, const int bitDepth, unsigned char **pngData, size_t *pngDataLength);
extern int writeGrayscaleAlphaIntoPNGBuffer(const unsigned char *gaData, const size_t width, const size_t height, const int bitDepth, unsigned char **pngData, size_t *pngDataLength);
extern int writeGrayscaleIntoPNGBuffer(const unsigned char *gData, const size_t width, const size_t height, const int bitDepth, unsigned char **pngData, size_t *pngDataLength);

#endif //COMMON_FUNCTIONS_PNG_H
