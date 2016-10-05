//
// Created by Michal Ziobro on 30/09/2016.
//

#ifndef COMMON_FUNCTIONS_PNG_H
#define COMMON_FUNCTIONS_PNG_H

#include <ntsid.h>

extern int writeDataAsPNGFile(const unsigned char *data, const size_t width, const size_t height, const int bitDepth, const int colorType, const char *filePath);
extern int writeRGBAasPNGFile(const unsigned char *rgbaData, const size_t width, const size_t height, const int bitDepth, const char *filePath);
extern int writeRGBasPNGFile(const unsigned char *rgbData, const size_t width, const size_t height, const int bitDepth, const char *filePath);
extern int writeGrayscaleAlphaAsPNGFile(const unsigned char *gaData, const size_t width, const size_t height, const int bitDepth, const char *filePath);
extern int writeGrayscaleAsPNGFile(const unsigned char *gData, const size_t width, const size_t height, const int bitDepth, const char *filePath);

extern int writeDataIntoPNGBuffer(const unsigned char *data, const size_t width, const size_t height, const int bitDepth, const int colorType, unsigned char *pngBuffer, size_t *pngBufferLength);
extern int writeRGBAintoPNGBuffer(const unsigned char *rgbaData, const size_t width, const size_t height, const int bitDepth, unsigned char *pngBuffer, size_t *pngBufferLength);
extern int writeRGBintoPNGBuffer(const unsigned char *rgbData, const size_t width, const size_t height, const int bitDepth, unsigned char *pngBuffer, size_t *pngBufferLength);
extern int writeGrayscaleAlphaIntoPNGBuffer(const unsigned char *gaData, const size_t width, const size_t height, const int bitDepth, unsigned char *pngBuffer, size_t *pngBufferLength);
extern int writeGrayscaleIntoPNGBuffer(const unsigned char *gData, const size_t width, const size_t height, const int bitDepth, unsigned char *pngBuffer, size_t *pngBufferLength);

#endif //COMMON_FUNCTIONS_PNG_H
