//
// Created by Michal Ziobro on 04/10/2016.
//

#include <stdlib.h>
#include <printf.h>
#include "bitmaps.h"

unsigned char *RGBABytesArraySkipAlpha(const unsigned char *rgbaData, const size_t rgbaDataLength, size_t *rgbDataLength) {

    size_t newDataLength = (rgbaDataLength*RGB_COMPONENTS_PER_PIXEL)/RGBA_COMPONENTS_PER_PIXEL;

    unsigned char *rgbData = malloc(sizeof(unsigned char)*newDataLength);
    if(rgbData == 0) {
        if(rgbDataLength) *rgbDataLength = 0;
        return 0;
    }

    for(int i=0, j=0; i<rgbaDataLength; i++) {
        if(i%4 == 3) continue;
        rgbData[j] = rgbaData[i];
        j++;
    }

    if(rgbDataLength) *rgbDataLength = newDataLength;
    return rgbData;
}

unsigned char *ARGBBytesArraySkipAlpha(const unsigned char *argbData, const size_t argbDataLength, size_t *rgbDataLength) {

    size_t newDataLength = (argbDataLength*RGB_COMPONENTS_PER_PIXEL)/ARGB_COMPONENTS_PER_PIXEL;

    unsigned char *rgbData = malloc(sizeof(unsigned char)*newDataLength);
    if(rgbData == 0) {
        if(rgbDataLength) *rgbDataLength = 0;
        return 0;
    }

    for(int i=0, j=0; i<argbDataLength; i++) {
        if(i%4 == 0) continue;
        rgbData[j] = argbData[i];
        j++;
    }

    if(rgbDataLength) *rgbDataLength = newDataLength;
    return rgbData;
}

unsigned char *RGBBytesArrayPrependAlpha(const unsigned char *rgbData, const size_t rgbDataLength, const unsigned char alphaByte, size_t *argbDataLength) {

    size_t newDataLength = (rgbDataLength*ARGB_COMPONENTS_PER_PIXEL)/RGB_COMPONENTS_PER_PIXEL;

    unsigned char *argbData = malloc(sizeof(unsigned char)*newDataLength);
    if(argbData == 0) {
        if(argbDataLength) *argbDataLength = 0;
        return 0;
    }

    for(int i=0, j=0; j < newDataLength; j++) {
        if(j%4 == 0)
            argbData[j] = alphaByte;
        else
            argbData[j] = rgbData[i++];
    }

    if(argbDataLength) *argbDataLength = newDataLength;
    return argbData;
}

unsigned char *RGBBytesArrayAppendAlpha(const unsigned char *rgbData, const size_t rgbDataLength, const unsigned char alphaByte, size_t *rgbaDataLength) {

    size_t newDataLength = (rgbDataLength*RGBA_COMPONENTS_PER_PIXEL)/RGB_COMPONENTS_PER_PIXEL;

    unsigned char *rgbaData = malloc(sizeof(unsigned char)*newDataLength);
    if(rgbaData == 0) {
        if(rgbaDataLength) *rgbaDataLength = 0;
        return 0;
    }

    for(int i=0, j=0; j < newDataLength; j++) {
        if(j%4 == 3)
            rgbaData[j] = alphaByte;
        else
            rgbaData[j] = rgbData[i++];
    }

    if(rgbaDataLength) *rgbaDataLength = newDataLength;
    return rgbaData;
}

void RGBABytesArraySetAlpha(unsigned char *rgbaData, const size_t rgbaDataLength, const unsigned char alphaByte) {

    for(int i=0; i < rgbaDataLength; i++)
        if(i%4 == 3) rgbaData[i] = alphaByte;
}

void ARGBBytesArraySetAlpha(unsigned char *argbData, const size_t argbDataLength, const unsigned char alphaByte) {

    for(int i=0; i < argbDataLength; i++)
        if(i%4 == 0) argbData[i] = alphaByte;
}

void PixelBytesArrayDump(const unsigned char *bytes, size_t width, size_t height, size_t bytesPerRow, size_t componentsPerPixel) {

    printf("Pixel Bytes Array:\n");
    for (int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            const uint8_t *px = &bytes[i*bytesPerRow + j*componentsPerPixel];
            printf("[");
            for(int c = 0; c < componentsPerPixel; c++) {
                printf("%02X", px[c]);
                if( c < componentsPerPixel -1) printf(" ");
            }
            printf("]");
            if(j < width -1) printf(" ");
        }
        printf("\n");
        break;
    }
}

unsigned char convertRGBColorToGrayColor(const unsigned char R, const unsigned char G, const unsigned char B) {

    return 0.299*R+0.587*G+0.114*B;
}

unsigned char *RGBABytesArrayToGrayscaleAlphaBytesArray(const unsigned char *rgbaData, const size_t rgbaDataLength, size_t *gaDataLength) {

    size_t newDataLength = (rgbaDataLength*GRAYSCALE_ALPHA_COMPONENTS_PER_PIXEL)/RGBA_COMPONENTS_PER_PIXEL;

    unsigned char *gaData = malloc(sizeof(unsigned char)*newDataLength);
    if(gaData == 0) {
        if(gaDataLength) *gaDataLength = 0;
        return 0;
    }

    for(int i=0; i<newDataLength; i++) {
        if(i%2 == 0) {
            // RGB to Grayscale conversion
            gaData[i] = convertRGBColorToGrayColor(rgbaData[2*i], rgbaData[2*i+1], rgbaData[2*i+2]);
        } else {
            // copy Alpha channel
            gaData[i] = rgbaData[2*i+1];
        }
    }

    if(gaDataLength) *gaDataLength = newDataLength;
    return gaData;
}

unsigned char *RGBBytesArrayToGrayscaleBytesArray(const unsigned char *rgbData, const size_t rgbDataLength, size_t *gDataLength) {

    size_t newDataLength = (rgbDataLength*GRAYSCALE_COMPONENTS_PER_PIXEL)/RGB_COMPONENTS_PER_PIXEL;

    unsigned char *gData = malloc(sizeof(unsigned char)*newDataLength);
    if(gData == 0) {
        if(gDataLength) *gDataLength = 0;
        return 0;
    }

    for(int i=0; i<newDataLength; i++) {
        // RGB to Grayscale conversion
        gData[i] = convertRGBColorToGrayColor(rgbData[3*i], rgbData[3*i+1], rgbData[3*i+2]);
    }

    if(gDataLength) *gDataLength = newDataLength;
    return gData;
}

unsigned char *GrayscaleBytesArrayAppendAlpha(const unsigned char*gData, const size_t gDataLength, const unsigned char alphaByte, size_t *gaDataLength) {

    size_t newDataLength = (gDataLength*GRAYSCALE_ALPHA_COMPONENTS_PER_PIXEL)/GRAYSCALE_COMPONENTS_PER_PIXEL;

    unsigned char *gaData = malloc(sizeof(unsigned char)*newDataLength);
    if(gaData == 0) {
        if(gaDataLength) *gaDataLength = 0;
        return 0;
    }

    for(int i=0; i<gDataLength; i++) {
        gaData[2*i] = gData[i];     // copy Grayscale channel
        gaData[2*i+1] = alphaByte;  // append Alpha channel
    }

    if(gaDataLength) *gaDataLength = newDataLength;
    return gaData;
}

unsigned char *GrayscaleAlphaBytesArraySkipAlpha(const unsigned char *gaData, const size_t gaDataLength, size_t *gDataLength) {

    size_t newDataLength = (gaDataLength*GRAYSCALE_COMPONENTS_PER_PIXEL)/GRAYSCALE_ALPHA_COMPONENTS_PER_PIXEL;

    unsigned char *gData = malloc(sizeof(unsigned char)*newDataLength);
    if(gData == 0) {
        if(gDataLength) *gDataLength = 0;
        return 0;
    }

    for(int i=0; i<newDataLength; i++) {
        gData[i] = gaData[2*i];     // copy Grayscale channel (and skip Alpha channel)
    }

    if(gDataLength) *gDataLength = newDataLength;
    return gData;
}