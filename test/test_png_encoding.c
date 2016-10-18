//
// Created by Michal Ziobro on 04/10/2016.
//

#include <stdio.h>
#include "test_png_encoding.h"
#include "../libraries/png/png-decoding.h"
#include "../../unit_tests/test/assertion.h"
#include "../libraries/png/png-encoding.h"
#include "../libraries/png/png-helper.h"
#include "../bitmaps.h"
#include "../bitwise.h"

static void test_write_RGBA_as_PNG_file(void) {

    unsigned char *rgbaData = 0;
    size_t rgbaDataLength = 0;
    size_t width = 0, height = 0;

    int r_result = readRGBAfromPNGFile("./test/resources/RGBA_8bits.png", &rgbaData, &rgbaDataLength, &width, &height, NULL);
    assert_equal_int(r_result, 0, "reading RGBA form PNG file succeeds");

    int w_result = writeRGBAasPNGFile(rgbaData, width, height, PNG_BIT_DEPTH_8, "/Users/michzio/Desktop/test_rgba.png");
    assert_equal_int(w_result, 0, "writing RGBA as PNG file succeeds");
}

static void test_write_RGB_as_PNG_file(void) {

    unsigned char *rgbaData = 0;
    size_t rgbaDataLength = 0;
    size_t width = 0, height = 0;

    int r_result = readRGBAfromPNGFile("./test/resources/RGBA_8bits.png", &rgbaData, &rgbaDataLength, &width, &height, NULL);
    assert_equal_int(r_result, 0, "reading RGBA form PNG file succeeds");

    unsigned char *rgbData = 0;
    size_t rgbDataLength = 0;

    rgbData = RGBABytesArraySkipAlpha(rgbaData, rgbaDataLength, &rgbDataLength);

    int w_result = writeRGBasPNGFile(rgbData, width, height, PNG_BIT_DEPTH_8,"/Users/michzio/Desktop/test_rgb.png");
    assert_equal_int(w_result, 0, "writing RGBA as PNG file succeeds");
}

static void test_write_Grayscale_Alpha_as_PNG_file(void) {

    unsigned char *rgbaData = 0;
    size_t rgbaDataLength = 0;
    size_t width = 0, height = 0;

    int r_result = readRGBAfromPNGFile("./test/resources/RGBA_8bits.png", &rgbaData, &rgbaDataLength, &width, &height, NULL);
    assert_equal_int(r_result, 0, "reading RGBA from PNG file succeeds");

    unsigned char *gaData = 0;
    size_t gaDataLength = 0;

    gaData = RGBABytesArrayToGrayscaleAlphaBytesArray(rgbaData, rgbaDataLength, &gaDataLength);
    assert_not_null(gaData, "converting RGBA to Grayscale Alpha succeeds");

    int w_result = writeGrayscaleAlphaAsPNGFile(gaData, width, height, PNG_BIT_DEPTH_8, "/Users/michzio/Desktop/test_ga.png");
    assert_equal_int(w_result, 0, "writing Grayscale Alpha as PNG file succeeds");
}

static void test_write_Grayscale_as_PNG_file(void) {

    unsigned char *rgbaData = 0;
    size_t rgbaDataLength = 0;
    size_t width = 0, height = 0;

    int r_result = readRGBAfromPNGFile("./test/resources/RGBA_8bits.png", &rgbaData, &rgbaDataLength, &width, &height, NULL);
    assert_equal_int(r_result, 0, "reading RGBA from PNG file succeeds");

    unsigned char *gaData = 0;
    size_t gaDataLength = 0;

    gaData = RGBABytesArrayToGrayscaleAlphaBytesArray(rgbaData, rgbaDataLength, &gaDataLength);
    assert_not_null(gaData, "converting RGBA to Grayscale Alpha succeeds");

    unsigned char *gData = 0;
    size_t gDataLength = 0;

    gData = GrayscaleAlphaBytesArraySkipAlpha(gaData, gaDataLength, &gDataLength);

    int w_result = writeGrayscaleAsPNGFile(gData, width, height, PNG_BIT_DEPTH_8, "/Users/michzio/Desktop/test_g.png");
    assert_equal_int(w_result, 0, "writing Grayscale as PNG file succeeds");

}

static void test_write_RGBA_to_PNG_buffer(void) {

    // read PNG file to RGBA
    unsigned char *rgbaData = 0;
    size_t rgbaDataLength = 0;
    size_t width = 0, height = 0;

    int rf_result = readRGBAfromPNGFile("./test/resources/RGBA_8bits.png", &rgbaData, &rgbaDataLength, &width, &height, NULL);
    assert_equal_int(rf_result, 0, "reading RGBA form PNG file succeeds");

    // write RGBA to PNG buffer
    unsigned char *pngData = 0;
    size_t pngDataLength = 0;

    int wb_result = writeRGBAintoPNGBuffer(rgbaData, width, height, PNG_BIT_DEPTH_8, &pngData, &pngDataLength);
    assert_equal_int(wb_result, 0, "writing RGBA to PNG buffer succeeds");
    assert_not_null(pngData, "encoding RGBA into PNG buffer succeeds");

    // printing png bytes out into console
    // bytes_array_dump(pngData, pngDataLength, 50);

    // writing png bytes into file
    fwrite_binaries("/Users/michzio/Desktop/test_write_rgba_to_png_buffer.png", pngData, pngDataLength);

    bool isPNG = isPNGFile("/Users/michzio/Desktop/test_write_rgba_to_png_buffer.png");
    assert_equal_int(isPNG, true, "encoded image data saved to file");

    float compression_ratio = (float)pngDataLength/rgbaDataLength;
    printf("RGBA/PNG compression ratio: %zu/%zu = %.2f\n", pngDataLength, rgbaDataLength, compression_ratio);
}

static void run_tests(void) {
    test_write_RGBA_as_PNG_file();
    test_write_RGB_as_PNG_file();
    test_write_Grayscale_Alpha_as_PNG_file();
    test_write_Grayscale_as_PNG_file();
    test_write_RGBA_to_PNG_buffer();

}

test_png_encoding_t test_png_encoding = { .run_tests = run_tests };