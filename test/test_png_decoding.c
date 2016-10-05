//
// Created by Michal Ziobro on 03/10/2016.
//

#include <printf.h>
#include "test_png_decoding.h"
#include "../libraries/png/png-decoding.h"
#include "../../unit_tests/test/assertion.h"

static void test_is_png_file(void) {
    bool isPNG = isPNGFile("./test/resources/RGB_8bits.png");
    assert_equal_int(isPNG, true, __func__);
}
static void test_is_not_png_file(void) {
    bool isPNG = isPNGFile("./test/resources/Jpeg.jpeg");
    assert_equal_int(isPNG, false, __func__);
}

static void test_read_RGBA_from_RGB_PNG_file(void) {

    unsigned char *rgbaData = 0;
    size_t rgbaDataLength = 0;
    size_t width = 0, height = 0;

    int result = readRGBAfromPNGFile("./test/resources/RGB_8bits.png", &rgbaData, &rgbaDataLength, &width, &height, NULL);
    assert_equal_int(result, -1, "reading RGBA from RGB PNG file fails");
    assert_null(rgbaData, "RGBA data from RGB PNG file");
}

static void test_read_RGBA_from_RGBA_PNG_file(void) {

    unsigned char *rgbaData = 0;
    size_t rgbaDataLength = 0;
    size_t width = 0, height = 0;

    int result = readRGBAfromPNGFile("./test/resources/RGBA_8bits.png", &rgbaData, &rgbaDataLength, &width, &height, NULL);
    assert_equal_int(result, 0, "reading RGBA form RGBA PNG file succeeds");
    assert_not_null(rgbaData, "RGBA data from RGBA PNG file");

    // print RGBA bytes array of read PNG image to console
    // bytes_array_dump(rgbaData, rgbaDataLength, width*4);
}

static void test_read_RGB_from_RGB_PNG_file(void) {

    unsigned char *rgbData = 0;
    size_t rgbDataLength = 0;
    size_t width = 0, height = 0;

    int result = readRGBfromPNGFile("./test/resources/RGB_8bits.png", &rgbData, &rgbDataLength, &width, &height, NULL);
    assert_equal_int(result, 0, "reading RGB from RGB PNG file succeeds");
    assert_not_null(rgbData, "RGB data from RGB PNG file");
}

static void test_read_Grayscale_from_Grayscale_PNG_file(void) {

    unsigned char *gData = 0;
    size_t gDataLength = 0;
    size_t width = 0, height = 0;

    int result = readGrayscaleFromPNGFile("./test/resources/Grayscale_8bits.png", &gData, &gDataLength, &width, &height, NULL);
    assert_equal_int(result, 0, "reading Grayscale from Grayscale PNG file succeeds");
    assert_not_null(gData, "Grayscale data from Grayscale PNG file");

    // print Grayscale bytes array of read PNG image to console
    // bytes_array_dump(gData, gDataLength, width*1);
}

static void test_read_GrayscaleAlpha_from_GrayscaleAlpha_PNG_file(void) {

    unsigned char *gaData = 0;
    size_t gaDataLength = 0;
    size_t width = 0, height = 0;

    int result = readGrayscaleAlphaFromPNGFile("./test/resources/Grayscale_Alpha_8bits.png", &gaData, &gaDataLength, &width, &height, NULL);
    assert_equal_int(result, 0, "reading Grayscale Alpha from Grayscale Alpha PNG file succeeds");
    assert_not_null(gaData, "Grayscale Alpha data from Grayscale Alpha PNG file");

    // print Grayscale Alpha bytes array of read PNG image to console
    // bytes_array_dump(gaData, gaDataLength, width*2);
}

static void run_tests(void) {
    test_is_png_file();
    test_is_not_png_file();
    test_read_RGBA_from_RGB_PNG_file();
    test_read_RGBA_from_RGBA_PNG_file();
    test_read_RGB_from_RGB_PNG_file();
    test_read_Grayscale_from_Grayscale_PNG_file();
    test_read_GrayscaleAlpha_from_GrayscaleAlpha_PNG_file();
}

test_png_decoding_t test_png_decoding = { .run_tests = run_tests };