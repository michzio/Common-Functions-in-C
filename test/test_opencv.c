//
// Created by Michal Ziobro on 06/10/2016.
//
#ifdef __CYGWIN__
#include <opencv2/core/fast_math.hpp>
#endif

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>
#include "test_opencv.h"
#include "../libraries/png/png-decoding.h"
#include "../bitmaps.h"
#include "../../unit_tests/test/assertion.h"
#include "../libraries/png/png-encoding.h"
#include "../libraries/png/png-helper.h"
#include "../bitwise.h"

#ifdef __APPLE__
static void test_display_image(void) {
    IplImage *image;
    image= cvLoadImage("./test/resources/RGBA_8bits.png", CV_LOAD_IMAGE_COLOR);
    cvNamedWindow("OpenCV Image Loading", CV_WINDOW_FREERATIO);
    cvShowImage("OpenCV Image Loading", image);
    cvWaitKey(0);

    cvDestroyWindow("OpenCV Image Loading");
    cvReleaseImage(&image);
}
#endif

static void test_cv_image(void) {

    unsigned char *rgbaData = 0, *bgraData = 0;
    size_t rgbaDataLength = 0;
    size_t width = 0, height = 0;

    int result = readRGBAfromPNGFile("./test/resources/RGBA_8bits.png",&rgbaData, &rgbaDataLength, &width, &height, NULL);
    bgraData = RGBABytesArray2BGRABytesArray(rgbaData, rgbaDataLength);

    IplImage *image = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 4);
    cvSetData(image, bgraData, image->widthStep);

    cvNamedWindow("OpenCV RGBA Image", CV_WINDOW_FREERATIO);
    cvShowImage("OpenCV RGBA Image", image);
    cvWaitKey(0);

    cvDestroyWindow("OpenCV RGBA Image");
    cvReleaseImage(&image);
    free(rgbaData);
    free(bgraData);
}

static void test_cv_image_resize(void) {

    unsigned char *rgbaData = 0;
    size_t rgbaDataLength = 0;
    size_t width = 0, height = 0;

    int result = readRGBAfromPNGFile("./test/resources/RGBA_8bits.png", &rgbaData, &rgbaDataLength, &width, &height, NULL);

    IplImage *image = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 4);
    cvSetData(image, rgbaData, image->widthStep);

    // resize image
    float scale = 1.5;
    IplImage *resizedImage = cvCreateImage(cvSize(image->width*scale, image->height*scale), image->depth, image->nChannels);
    //cvResize(image, resizedImage, CV_INTER_AREA);
    cvResize(image, resizedImage, CV_INTER_LINEAR);

    // display resized image
    cvNamedWindow("OpenCV Resized Image", CV_WINDOW_FREERATIO);
    cvShowImage("OpenCV Resized Image", resizedImage);
    cvWaitKey(0);

    cvDestroyWindow("OpenCV Resized Image");
    cvReleaseImage(&image);
    cvReleaseImage(&resizedImage);
    free(rgbaData);
}

static void test_rgba_resize(void) {

    double scaleFactor = 0.5;

    unsigned char *rgbaData = 0;
    size_t rgbaDataLength = 0;
    size_t width = 0, height = 0;

    int read_result = readRGBAfromPNGFile("./test/resources/RGBA_8bits.png", &rgbaData, &rgbaDataLength, &width, &height, NULL);
    assert_equal_int(read_result, 0, "reading RGBA from PNG file succeeds");

    unsigned char *newRgbaData = 0;
    size_t newRgbaDataLength = 0;
    size_t new_width = scaleFactor*width, new_height = scaleFactor*height;

    int resize_result = resizeRGBA(rgbaData, rgbaDataLength, width, height, PNG_BIT_DEPTH_8,
                                    &newRgbaData, &newRgbaDataLength, new_width, new_height );
    assert_equal_int(resize_result, 0, "resizing RGBA bitmap succeeds");
    assert_not_null(newRgbaData, "resized RGBA bitmap not null");

    int write_result = writeRGBAasPNGFile(newRgbaData, new_width, new_height, PNG_BIT_DEPTH_8, "/Users/michzio/Desktop/test_rgba_resize.png");
    bool isPNG = isPNGFile("/Users/michzio/Desktop/test_rgba_resize.png");
    assert_equal_int(isPNG, true, "writing resized RGBA bitmap to PNG file succeeds");

    printf("scale factor: %.2f -> size ratio: %.2f\n", scaleFactor, ((double) newRgbaDataLength)/rgbaDataLength);

    free(rgbaData);
}

static void test_rgb_resize(void) {

    double scaleFactor = 0.5;

    unsigned char *rgbData = 0;
    size_t rgbDataLength = 0;
    size_t width = 0, height = 0;

    int read_result = readRGBfromPNGFile("./test/resources/RGB_8bits.png", &rgbData, &rgbDataLength, &width, &height, NULL);
    assert_equal_int(read_result, 0, "reading RGB from PNG file succeeds");

    unsigned char *newRgbData = 0;
    size_t newRgbDataLength = 0;
    size_t new_width = scaleFactor*width, new_height = scaleFactor*height;

    int resize_result = resizeRGB(rgbData, rgbDataLength, width, height, PNG_BIT_DEPTH_8,
                                    &newRgbData, &newRgbDataLength, new_width, new_height);
    assert_equal_int(resize_result, 0, "resizing RGB bitmap succeeds");
    assert_not_null(newRgbData, "resized RGB bitmap not null");

    int write_result = writeRGBasPNGFile(newRgbData, new_width, new_height, PNG_BIT_DEPTH_8, "/Users/michzio/Desktop/test_rgb_resize.png");
    bool isPNG = isPNGFile("/Users/michzio/Desktop/test_rgb_resize.png");
    assert_equal_int(isPNG, true, "writing resized RGB bitmap to PNG file succeeds");

    printf("scale factor: %.2f -> size ratio: %.2f\n", scaleFactor, ((double) newRgbDataLength)/rgbDataLength );

    free(rgbData);
}

static void test_grayscale_alpha_resize() {

    double scaleFactor = 0.5;

    unsigned char *gaData = 0;
    size_t gaDataLength = 0;
    size_t width = 0, height = 0;

    int read_result = readGrayscaleAlphaFromPNGFile("./test/resources/Grayscale_Alpha_8bits.png", &gaData, &gaDataLength, &width, &height, NULL);
    assert_equal_int(read_result, 0, "reading Grayscale Alpha from PNG file succeeds");

    unsigned char *newGaData = 0;
    size_t newGaDataLength = 0;
    size_t new_width = scaleFactor*width, new_height = scaleFactor*height;

    int resize_result = resizeGrayscaleAlpha(gaData, gaDataLength, width, height, PNG_BIT_DEPTH_8,
                                            &newGaData, &newGaDataLength, new_width, new_height);
    assert_equal_int(resize_result, 0, "resizing Grayscale Alpha bitmap succeeds");
    assert_not_null(newGaData, "resized Grayscale Alpha bitmap not null");

    int write_result = writeGrayscaleAlphaAsPNGFile(newGaData, new_width, new_height, PNG_BIT_DEPTH_8, "/Users/michzio/Desktop/test_ga_resize.png");
    bool isPNG = isPNGFile("/Users/michzio/Desktop/test_ga_resize.png");
    assert_equal_int(isPNG, true, "writing resized Grayscale Alpha bitmap to PNG file succeeds");

    printf("scale factor: %.2f -> size ratio: %.2f\n", scaleFactor, ((double) newGaDataLength)/gaDataLength );

    free(gaData);
}

static void test_grayscale_resize() {

    double scaleFactor = 0.5;

    unsigned char *gData = 0;
    size_t gDataLength = 0;
    size_t width = 0, height = 0;

    int read_result = readGrayscaleFromPNGFile("./test/resources/Grayscale_8bits.png", &gData, &gDataLength, &width, &height, NULL);
    assert_equal_int(read_result, 0, "reading Grayscale from PNG file succeeds");

    unsigned char *paddedData = 0;
    size_t paddedDataLength = 0;
    int padding = padBitmap(gData, gDataLength, width, height, PNG_BIT_DEPTH_8, GRAYSCALE_COMPONENTS_PER_PIXEL, &paddedData, &paddedDataLength, 4);
    width += padding;

    unsigned char *newGData = 0;
    size_t newGDataLength = 0;
    size_t new_width = scaleFactor*width, new_height = scaleFactor*height;

    int resize_result = resizeGrayscale(paddedData, paddedDataLength, width, height, PNG_BIT_DEPTH_8,
                                        &newGData, &newGDataLength, new_width, new_height);
    assert_equal_int(resize_result, 0, "resizing Grayscale bitmap succeeds");
    assert_not_null(newGData, "resized Grayscale bitmap not null");

    int write_result = writeGrayscaleAsPNGFile(newGData, new_width, new_height, PNG_BIT_DEPTH_8, "/Users/michzio/Desktop/test_g_resize.png");
    bool isPNG = isPNGFile("/Users/michzio/Desktop/test_g_resize.png");
    assert_equal_int(isPNG, true, "writing resized Grayscale bitmap to PNG file succeeds");

    printf("scale factor: %.2f -> size ratio: %.2f\n", scaleFactor, ((double) newGDataLength)/gDataLength );

    free(gData);
}

static void test_rgba_scale(void) {

    double scaleFactor = 2.0;

    unsigned char *rgbaData = 0;
    size_t rgbaDataLength = 0;
    size_t width = 0, height = 0;

    int read_result = readRGBAfromPNGFile("./test/resources/RGBA_8bits.png", &rgbaData, &rgbaDataLength, &width, &height, NULL);
    assert_equal_int(read_result, 0, "reading RGBA from PNG file succeeds");

    unsigned char *newRgbaData = 0;
    size_t newRgbaDataLength = 0;
    size_t new_width = scaleFactor*width, new_height = scaleFactor*height;

    int scale_result = scaleRGBA(rgbaData, rgbaDataLength, width, height, PNG_BIT_DEPTH_8,
                                 &newRgbaData, &newRgbaDataLength, scaleFactor);
    assert_equal_int(scale_result, 0, "scaling RGBA bitmap succeeds");
    assert_not_null(newRgbaData, "scaled RGBA bitmap not null");

    int write_result = writeRGBAasPNGFile(newRgbaData, new_width, new_height, PNG_BIT_DEPTH_8, "/Users/michzio/Desktop/test_rgba_scale.png");
    bool isPNG = isPNGFile("/Users/michzio/Desktop/test_rgba_scale.png");
    assert_equal_int(isPNG, true, "writing scaled RGBA bitmap to PNG file succeeds");

    printf("scale factor: %.2f -> size ratio: %.2f\n", scaleFactor, ((double) newRgbaDataLength)/rgbaDataLength);

    free(rgbaData);
}

static void test_rgb_scale() {

    double scaleFactor = 2.0;

    unsigned char *rgbData = 0;
    size_t rgbDataLength = 0;
    size_t width = 0, height = 0;

    int read_result = readRGBfromPNGFile("./test/resources/RGB_8bits.png", &rgbData, &rgbDataLength, &width, &height, NULL);
    assert_equal_int(read_result, 0, "reading RGB from PNG file succeeds");

    unsigned char *newRgbData = 0;
    size_t newRgbDataLength = 0;
    size_t new_width = scaleFactor*width, new_height = scaleFactor*height;

    int scale_result = scaleRGB(rgbData, rgbDataLength, width, height, PNG_BIT_DEPTH_8,
                                &newRgbData, &newRgbDataLength, scaleFactor);
    assert_equal_int(scale_result, 0, "scaling RGB bitmap succeeds");
    assert_not_null(newRgbData, "scaled RGB bitmap not null");

    int write_result = writeRGBasPNGFile(newRgbData, new_width, new_height, PNG_BIT_DEPTH_8, "/Users/michzio/Desktop/test_rgb_scale.png");
    bool isPNG = isPNGFile("/Users/michzio/Desktop/test_rgb_scale.png");
    assert_equal_int(isPNG, true, "writing scaled RGB bitmap to PNG file succeeds");

    printf("scale factor: %.2f -> size ratio: %.2f\n", scaleFactor, ((double) newRgbDataLength)/rgbDataLength);

    free(rgbData);
}

static void test_grayscale_alpha_scale() {

    double scaleFactor = 2.0;

    unsigned char *gaData = 0;
    size_t gaDataLength = 0;
    size_t width = 0, height = 0;

    int read_result = readGrayscaleAlphaFromPNGFile("./test/resources/Grayscale_Alpha_8bits.png", &gaData, &gaDataLength, &width, &height, NULL);
    assert_equal_int(read_result, 0, "reading Grayscale Alpha from PNG file succeeds");

    unsigned char *newGaData = 0;
    size_t newGaDataLength = 0;
    size_t new_width = scaleFactor*width, new_height = scaleFactor*height;

    int scale_result = scaleGrayscaleAlpha(gaData, gaDataLength, width, height, PNG_BIT_DEPTH_8,
                                            &newGaData, &newGaDataLength, scaleFactor);
    assert_equal_int(scale_result, 0, "scaling Grayscale Alpha bitmap succeeds");
    assert_not_null(newGaData, "scaled Grayscale Alpha bitmap not null");

    int write_result = writeGrayscaleAlphaAsPNGFile(newGaData, new_width, new_height, PNG_BIT_DEPTH_8, "/Users/michzio/Desktop/test_ga_scale.png");
    bool isPNG = isPNGFile("/Users/michzio/Desktop/test_ga_scale.png");
    assert_equal_int(isPNG, true, "writing scaled Grayscale Alpha bitmap to PNG file succeeds");

    printf("scale factor: %.2f -> size ratio: %.2f\n", scaleFactor, ((double) newGaDataLength)/gaDataLength );

    free(gaData);
}

static void test_grayscale_scale() {

    double scaleFactor = 0.5;

    unsigned char *gData = 0;
    size_t gDataLength = 0;
    size_t width = 0, height = 0;

    int read_result = readGrayscaleFromPNGFile("./test/resources/Grayscale_8bits.png", &gData, &gDataLength, &width, &height, NULL);

    unsigned char *paddedData = 0;
    size_t paddedDataLength = 0;
    int padding = padBitmap(gData, gDataLength, width, height, PNG_BIT_DEPTH_8, GRAYSCALE_COMPONENTS_PER_PIXEL, &paddedData, &paddedDataLength, 4);
    width += padding;

    //bytes_array_dump(paddedData, paddedDataLength, width);

    assert_equal_int(read_result, 0, "reading Grayscale from PNG file succeeds");

    unsigned char *newGData = 0;
    size_t newGDataLength = 0;
    size_t new_width = scaleFactor*width, new_height = scaleFactor*height;

    int scale_result = scaleGrayscale(paddedData, paddedDataLength, width, height, PNG_BIT_DEPTH_8,
                                        &newGData, &newGDataLength, scaleFactor);
    assert_equal_int(scale_result, 0, "scaling Grayscale bitmap succeeds");
    assert_not_null(newGData, "scaled Grayscale bitmap not null");

    int write_result = writeGrayscaleAsPNGFile(newGData, new_width, new_height, PNG_BIT_DEPTH_8, "/Users/michzio/Desktop/test_g_scale.png");
    bool isPNG = isPNGFile("/Users/michzio/Desktop/test_g_scale.png");
    assert_equal_int(isPNG, true, "writing scaled Grayscale bitmap to PNG file succeeds");

    printf("scale factor: %.2f -> size ratio: %.2f\n", scaleFactor, ((double) newGDataLength)/gDataLength );

    free(gData);
}

static void run_tests(void) {
    // test_display_image();
    // test_cv_image();
    // test_cv_image_resize();
    test_rgba_resize();
    test_rgb_resize();
    test_grayscale_alpha_resize();
    test_grayscale_resize();
    test_rgba_scale();
    test_rgb_scale();
    test_grayscale_alpha_scale();
    test_grayscale_scale();
}

test_opencv_t test_opencv = { .run_tests = run_tests };