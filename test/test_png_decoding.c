//
// Created by Michal Ziobro on 03/10/2016.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "test_png_decoding.h"
#include "../libraries/png/png-decoding.h"
#include "../libraries/png/png-encoding.h"
#include "../libraries/png/png-helper.h"
#include "../bitwise.h"
#include "../../unit_tests/test/assertion.h"
#include "../../unit_tests/common/terminal.h"
#include "../types.h"

#ifdef __APPLE__
    #define TEST_READ_GRAYSCALE_PNG_PATH "/Users/michzio/Desktop/test_read_grayscale.png"
    #define TEST_READ_RGBA_FROM_PNG_BUFFER_PNG_PATH "/Users/michzio/Desktop/test_read_rgba_from_png_buffer.png"
#elif __CYGWIN__
    #define TEST_READ_GRAYSCALE_PNG_PATH "C:/Users/michzio/Desktop/test_read_grayscale.png"
    #define TEST_READ_RGBA_FROM_PNG_BUFFER_PNG_PATH "C:/Users/michzio/Desktop/test_read_rgba_from_png_buffer.png"
#endif

static void test_is_png_file(void) {

    TEST_FUNCTION_HEADER;

    bool isPNG = isPNGFile("./test/resources/RGB_8bits.png");
    assert_equal_int(isPNG, true, __func__);
}

static void test_is_not_png_file(void) {

    TEST_FUNCTION_HEADER;

    bool isPNG = isPNGFile("./test/resources/Jpeg.jpeg");
    assert_equal_int(isPNG, false, __func__);
}

static void test_read_RGBA_from_RGB_PNG_file(void) {

    TEST_FUNCTION_HEADER;

    unsigned char *rgbaData = 0;
    size_t rgbaDataLength = 0;
    size_t width = 0, height = 0;

    int result = readRGBAfromPNGFile("./test/resources/RGB_8bits.png", &rgbaData, &rgbaDataLength, &width, &height, NULL);
    assert_equal_int(result, FAILURE, "reading RGBA from RGB PNG file fails");
    assert_null(rgbaData, "empty RGBA data from RGB PNG file");
}

static void test_read_RGBA_from_RGBA_PNG_file(void) {

    TEST_FUNCTION_HEADER;

    unsigned char *rgbaData = 0;
    size_t rgbaDataLength = 0;
    size_t width = 0, height = 0;

    int result = readRGBAfromPNGFile("./test/resources/RGBA_8bits.png", &rgbaData, &rgbaDataLength, &width, &height, NULL);
    assert_equal_int(result, SUCCESS, "reading RGBA form RGBA PNG file succeeds");
    assert_not_null(rgbaData, "RGBA data from RGBA PNG file");

    // print RGBA bytes array of read PNG image into console
    // bytes_array_dump(rgbaData, rgbaDataLength, width*4);
}

static void test_read_RGB_from_RGB_PNG_file(void) {

    TEST_FUNCTION_HEADER;

    unsigned char *rgbData = 0;
    size_t rgbDataLength = 0;
    size_t width = 0, height = 0;

    int result = readRGBfromPNGFile("./test/resources/RGB_8bits.png", &rgbData, &rgbDataLength, &width, &height, NULL);
    assert_equal_int(result, SUCCESS, "reading RGB from RGB PNG file succeeds");
    assert_not_null(rgbData, "RGB data from RGB PNG file");
}

static void test_read_Grayscale_from_Grayscale_PNG_file(void) {

    TEST_FUNCTION_HEADER;

    unsigned char *gData = 0;
    size_t gDataLength = 0;
    size_t width = 0, height = 0;

    int result = readGrayscaleFromPNGFile("./test/resources/Grayscale_8bits.png", &gData, &gDataLength, &width, &height, NULL);
    assert_equal_int(result, SUCCESS, "reading Grayscale from Grayscale PNG file succeeds");
    assert_not_null(gData, "Grayscale data from Grayscale PNG file");

    // print Grayscale bytes array of read PNG image into console
    // bytes_array_dump(gData, gDataLength, width*1);

    writeGrayscaleAsPNGFile(gData, width, height, PNG_BIT_DEPTH_8, TEST_READ_GRAYSCALE_PNG_PATH);
}

static void test_read_GrayscaleAlpha_from_GrayscaleAlpha_PNG_file(void) {

    TEST_FUNCTION_HEADER;

    unsigned char *gaData = 0;
    size_t gaDataLength = 0;
    size_t width = 0, height = 0;

    int result = readGrayscaleAlphaFromPNGFile("./test/resources/Grayscale_Alpha_8bits.png", &gaData, &gaDataLength, &width, &height, NULL);
    assert_equal_int(result, SUCCESS, "reading Grayscale Alpha from Grayscale Alpha PNG file succeeds");
    assert_not_null(gaData, "Grayscale Alpha data from Grayscale Alpha PNG file");

    // print Grayscale Alpha bytes array of read PNG image into console
    // bytes_array_dump(gaData, gaDataLength, width*2);
}

static void test_read_RGBA_from_PNG_buffer(void) {

    TEST_FUNCTION_HEADER;

    unsigned char *pngData = 0;
    size_t pngDataLength = 0;

    pngData = fread_binaries("./test/resources/RGBA_8bits.png", &pngDataLength);
    assert_not_null(pngData, "loading PNG from file to buffer succeeds");

    unsigned char *rgbaData = 0;
    size_t rgbaDataLength = 0;
    size_t width = 0, height = 0;

    int rb_result = readRGBAfromPNGBuffer(pngData, pngDataLength, &rgbaData, &rgbaDataLength, &width, &height, NULL);
    assert_equal_int(rb_result, SUCCESS, "reading RGBA from PNG buffer succeeds");
    assert_not_null(rgbaData, "decoded RGBA data from PNG buffer");

    // printing png bytes out into console
    // bytes_array_dump(pngData, pngDataLength, 50);

    int wf_result = writeRGBAasPNGFile(rgbaData, width, height, PNG_BIT_DEPTH_8, TEST_READ_RGBA_FROM_PNG_BUFFER_PNG_PATH);
    assert_equal_int(wf_result, SUCCESS, "writing RGBA to PNG file succeeds");

    float compression_ratio = (float)pngDataLength/rgbaDataLength;
    printf("PNG/RGBA compression ratio: %zu/%zu = %.2f\n", pngDataLength, rgbaDataLength, compression_ratio);
}

static void run_tests(void) {
    test_is_png_file();
    test_is_not_png_file();
    test_read_RGBA_from_RGB_PNG_file();
    test_read_RGBA_from_RGBA_PNG_file();
    test_read_RGB_from_RGB_PNG_file();
    test_read_Grayscale_from_Grayscale_PNG_file();
    test_read_GrayscaleAlpha_from_GrayscaleAlpha_PNG_file();
    test_read_RGBA_from_PNG_buffer();
}

test_png_decoding_t test_png_decoding = { .run_tests = run_tests };