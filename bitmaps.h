//
// Created by Michal Ziobro on 04/10/2016.
//

#ifndef COMMON_FUNCTIONS_BITMAPS_H
#define COMMON_FUNCTIONS_BITMAPS_H

#include <stddef.h>

#define COMPONENTS_PER_PIXEL 4
#define RGBA_COMPONENTS_PER_PIXEL COMPONENTS_PER_PIXEL
#define ARGB_COMPONENTS_PER_PIXEL COMPONENTS_PER_PIXEL
#define RGB_COMPONENTS_PER_PIXEL 3
#define GRAYSCALE_ALPHA_COMPONENTS_PER_PIXEL 2
#define GRAYSCALE_COMPONENTS_PER_PIXEL 1

unsigned char *RGBABytesArraySkipAlpha(const unsigned char *rgbaData, const size_t rgbaDataLength, size_t *rgbDataLength);
unsigned char *ARGBBytesArraySkipAlpha(const unsigned char *argbData, const size_t argbDataLength, size_t *rgbDataLength);
unsigned char *RGBBytesArrayPrependAlpha(const unsigned char *rgbData, const size_t rgbDataLength, const unsigned char alphaByte, size_t *argbDataLength);
unsigned char *RGBBytesArrayAppendAlpha(const unsigned char *rgbData, const size_t rgbDataLength, const unsigned char alphaByte, size_t *rgbaDataLength);
void RGBABytesArraySetAlpha(unsigned char *rgbaData, const size_t rgbaDataLength, const unsigned char alphaByte);
void ARGBBytesArraySetAlpha(unsigned char *argbData, const size_t argbDataLength, const unsigned char alphaByte);
void PixelBytesArrayDump(const unsigned char *bytes, size_t width, size_t height, size_t bytesPerRow, size_t componentsPerPixel);

unsigned char convertRGBColorToGrayColor(const unsigned char R, const unsigned char G, const unsigned char B);
unsigned char *RGBABytesArrayToGrayscaleAlphaBytesArray(const unsigned char *rgbaData, const size_t rgbaDataLength, size_t *gaDataLength);
unsigned char *RGBBytesArrayToGrayscaleBytesArray(const unsigned char *rgbData, const size_t rgbDataLength, size_t *gDataLength);
unsigned char *GrayscaleBytesArrayAppendAlpha(const unsigned char*gData, const size_t gDataLength, const unsigned char alphaByte, size_t *gaDataLength);
unsigned char *GrayscaleAlphaBytesArraySkipAlpha(const unsigned char *gaData, const size_t gaDataLength, size_t *gDataLength);

unsigned char *RGBABytesArray2BGRABytesArray(const unsigned char *rgbaData, const size_t rgbaDataLength);
unsigned char *RGBBytesArray2BGRBytesArray(const unsigned char *rgbData, const size_t rgbDataLength);
unsigned char *BGRABytesArray2RGBABytesArray(const unsigned char *bgraData, const size_t bgraDataLength);
unsigned char *BGRBytesArray2RGBBytesArray(const unsigned char *bgrData, const size_t bgrDataLength);

// resizing and scaling images stored as bitmaps (bytes array) using OpenCV library
int resizeBitmap(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
                 const int bitDepth, const int noOfChannels, unsigned char **outData, size_t *outDataLength, const size_t outWidth, const size_t outHeight);
int resizeRGBA(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
                const int bitDepth, unsigned char **outData, size_t *outDataLength, const size_t outWidth, const size_t outHeight);
int resizeRGB(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
               const int bitDepth, unsigned char **outData, size_t *outDataLength, const size_t outWidth, const size_t outHeight);
int resizeGrayscaleAlpha(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
              const int bitDepth, unsigned char **outData, size_t *outDataLength, const size_t outWidth, const size_t outHeight);
int resizeGrayscale(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
              const int bitDepth, unsigned char **outData, size_t *outDataLength, const size_t outWidth, const size_t outHeight);
int scaleBitmap(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
                const int bitDepth, const int noOfChannels, unsigned char **outData, size_t *outDataLength, const double scaleFactor);
int scaleRGBA(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
                const int bitDepth, unsigned char **outData, size_t *outDataLength, const double scaleFactor);
int scaleRGB(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
              const int bitDepth, unsigned char **outData, size_t *outDataLength, const double scaleFactor);
int scaleGrayscaleAlpha(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
             const int bitDepth, unsigned char **outData, size_t *outDataLength, const double scaleFactor);
int scaleGrayscale(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
             const int bitDepth, unsigned char **outData, size_t *outDataLength, const double scaleFactor);
int padBitmap(const unsigned char *data, const size_t dataLength, const size_t width, const size_t height,
              const int bitDepth, const int noOfChannels, unsigned char **paddedData, size_t *paddedDataLength, const size_t row_multiple);


#endif //COMMON_FUNCTIONS_BITMAPS_H