//
// Created by Michal Ziobro on 04/10/2016.
//

#ifdef __WIN32__
#include <opencv2/core/fast_math.hpp>
#include <opencv2/imgcodecs/imgcodecs_c.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>
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

unsigned char *RGBABytesArray2BGRABytesArray(const unsigned char *rgbaData, const size_t rgbaDataLength) {

    unsigned char *bgraData = malloc(sizeof(unsigned char) * rgbaDataLength);

    for(int i=0; i<rgbaDataLength; i+=4) {
        bgraData[i] = rgbaData[i+2];
        bgraData[i+1] = rgbaData[i+1];
        bgraData[i+2] = rgbaData[i];
        bgraData[i+3] = rgbaData[i+3];
    }

    return bgraData;
}

unsigned char *RGBBytesArray2BGRBytesArray(const unsigned char *rgbData, const size_t rgbDataLength) {

    unsigned char *bgrData = malloc(sizeof(unsigned char) * rgbDataLength);

    for(int i=0; i<rgbDataLength; i+=3) {
        bgrData[i] = rgbData[i+2];
        bgrData[i+1] = rgbData[i+1];
        bgrData[i+2] = rgbData[i];
    }

    return bgrData;
}

unsigned char *BGRABytesArray2RGBABytesArray(const unsigned char *bgraData, const size_t bgraDataLength) {
    return RGBABytesArray2BGRABytesArray(bgraData, bgraDataLength);
}

unsigned char *BGRBytesArray2RGBBytesArray(const unsigned char *bgrData, const size_t bgrDataLength) {
    return RGBBytesArray2BGRBytesArray(bgrData, bgrDataLength);
}

// resizing and scaling images stored as bitmaps (bytes array) using OpenCV library
int resizeBitmap(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
                 const int bitDepth, const int noOfChannels, unsigned char **outData, size_t *outDataLength, const size_t outWidth, const size_t outHeight) {

    // create input image
    IplImage *inImage = cvCreateImage(cvSize(inWidth, inHeight), bitDepth, noOfChannels);
    cvSetData(inImage, inData, inImage->widthStep);

    /* // show input image
        cvNamedWindow("OpenCV Input Image", CV_WINDOW_FREERATIO);
        cvShowImage("OpenCV Input Image", inImage);
        cvWaitKey(0);
        cvDestroyWindow("OpenCV Input Image");
     */

    // create output image
    IplImage *outImage = cvCreateImage(cvSize(outWidth, outHeight), inImage->depth, inImage->nChannels);

    // select interpolation type
    double scaleFactor = (((double) outWidth)/inWidth + ((double) outHeight)/inHeight)/2;
    int interpolation = (scaleFactor > 1.0) ? CV_INTER_LINEAR : CV_INTER_AREA;

    // resize from input image to output image
    cvResize(inImage, outImage, interpolation);

    /*  // show output image
        cvNamedWindow("OpenCV Output Image", CV_WINDOW_FREERATIO);
        cvShowImage("OpenCV Output Image", outImage);
        cvWaitKey(0);
        cvDestroyWindow("OpenCV Output Image");
    */

    // get raw data from output image
    int step = 0;
    CvSize size;
    cvGetRawData(outImage, outData, &step, &size);
    *outDataLength = step*size.height;

    cvReleaseImage(&inImage);
    cvReleaseImage(&outImage);

    return 0;
}

int resizeRGBA(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
               const int bitDepth, unsigned char **outData, size_t *outDataLength, const size_t outWidth, const size_t outHeight) {
    return resizeBitmap(inData, inDataLength, inWidth, inHeight, bitDepth, RGBA_COMPONENTS_PER_PIXEL, outData, outDataLength, outWidth, outHeight);
}

int resizeRGB(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
              const int bitDepth, unsigned char **outData, size_t *outDataLength, const size_t outWidth, const size_t outHeight) {
    return resizeBitmap(inData, inDataLength, inWidth, inHeight, bitDepth, RGB_COMPONENTS_PER_PIXEL, outData, outDataLength, outWidth, outHeight);
}

int resizeGrayscaleAlpha(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
                         const int bitDepth, unsigned char **outData, size_t *outDataLength, const size_t outWidth, const size_t outHeight) {
    return resizeBitmap(inData, inDataLength, inWidth, inHeight, bitDepth, GRAYSCALE_ALPHA_COMPONENTS_PER_PIXEL, outData, outDataLength, outWidth, outHeight);
}

int resizeGrayscale(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
                    const int bitDepth, unsigned char **outData, size_t *outDataLength, const size_t outWidth, const size_t outHeight) {
    return resizeBitmap(inData, inDataLength, inWidth, inHeight, bitDepth, GRAYSCALE_COMPONENTS_PER_PIXEL, outData, outDataLength, outWidth, outHeight);
}

int scaleBitmap(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
                const int bitDepth, const int noOfChannels, unsigned char **outData, size_t *outDataLength, const double scaleFactor) {

    // create input image
    IplImage *inImage = cvCreateImage(cvSize(inWidth, inHeight), bitDepth, noOfChannels);
    cvSetData(inImage, inData, (inWidth*noOfChannels*bitDepth)/CHAR_BIT);

    // create output image
    IplImage *outImage = cvCreateImage(cvSize(inWidth*scaleFactor, inHeight*scaleFactor), inImage->depth, inImage->nChannels);

    // select interpolation type
    int interpolation = (scaleFactor > 1.0) ? CV_INTER_LINEAR : CV_INTER_AREA;

    // resize from input image to output image
    cvResize(inImage, outImage, interpolation);

    // get raw data from output image
    int step = 0;
    CvSize size;
    cvGetRawData(outImage, outData, &step, &size);
    *outDataLength = step*size.height;

    cvReleaseImage(&inImage);
    cvReleaseImage(&outImage);

    return 0;
}

int scaleRGBA(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
              const int bitDepth, unsigned char **outData, size_t *outDataLength, const double scaleFactor) {
    return scaleBitmap(inData, inDataLength, inWidth, inHeight, bitDepth, RGBA_COMPONENTS_PER_PIXEL, outData, outDataLength, scaleFactor);
}

int scaleRGB(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
             const int bitDepth, unsigned char **outData, size_t *outDataLength, const double scaleFactor) {
    return scaleBitmap(inData, inDataLength, inWidth, inHeight, bitDepth, RGB_COMPONENTS_PER_PIXEL, outData, outDataLength, scaleFactor);
}

int scaleGrayscaleAlpha(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
                        const int bitDepth, unsigned char **outData, size_t *outDataLength, const double scaleFactor) {
    return scaleBitmap(inData, inDataLength, inWidth, inHeight, bitDepth, GRAYSCALE_ALPHA_COMPONENTS_PER_PIXEL, outData, outDataLength, scaleFactor);
}

int scaleGrayscale(const unsigned char *inData, const size_t inDataLength, const size_t inWidth, const size_t inHeight,
                   const int bitDepth, unsigned char **outData, size_t *outDataLength, const double scaleFactor) {
    return scaleBitmap(inData, inDataLength, inWidth, inHeight, bitDepth, GRAYSCALE_COMPONENTS_PER_PIXEL, outData, outDataLength, scaleFactor);
}

int padBitmap(const unsigned char *data, const size_t dataLength, const size_t width, const size_t height,
              const int bitDepth, const int noOfChannels, unsigned char **paddedData, size_t *paddedDataLength, const size_t row_multiple) {


    size_t row_length = (width*noOfChannels*bitDepth)/CHAR_BIT;
    size_t row_padding_size = row_multiple - row_length % row_multiple;

    if(row_padding_size == 0) return 0;

    size_t new_row_length = row_length + row_padding_size;
    size_t newDataLength = height * new_row_length;
    unsigned char *newData = malloc(sizeof(unsigned char) *newDataLength);

    unsigned char padding[3] = {0, 0, 0};
    for(int i=0; i<height; i++) {
        memcpy(newData + i*new_row_length, data + i*row_length, row_length);
        memcpy(newData + i*new_row_length + row_length, padding, row_padding_size);
    }

    *paddedData = newData;
    *paddedDataLength = newDataLength;

    return row_padding_size;
}