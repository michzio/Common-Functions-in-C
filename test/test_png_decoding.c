//
// Created by Michal Ziobro on 03/10/2016.
//

#include <printf.h>
#include "test_png_decoding.h"
#include "../libraries/png/png-decoding.h"
#include "../../unit_tests/test/assertion.h"

static void test_is_png_file(void) {
    bool isPNG = isPNGFile("./test/resources/Lion.png");
    assert_equal_int(isPNG, true, __func__);
}
static void test_is_not_png_file(void) {
    bool isPNG = isPNGFile("./test/resources/LionJpeg.jpeg");
    assert_equal_int(isPNG, false, __func__);
}

static void test_read_RGBA_from_grayscale_PNG_file(void) {

    unsigned char *rgbaData = 0;
    size_t rgbaDataLength = 0;
    size_t width = 0, height = 0;

    int result = readRGBAFromPNGFile("./test/resources/Lion.png", &rgbaData, &rgbaDataLength, &width, &height);
    assert_equal_int(result, -1, "reading RGBA from Grayscale PNG file fails");
    assert_null(rgbaData, "RGBA data from Grayscale PNG file");
}

static void test_read_RGBA_from_RGBA_PNG_file(void) {

    unsigned char *rgbaData = 0;
    size_t rgbaDataLength = 0;
    size_t width = 0, height = 0;

    int result = readRGBAFromPNGFile("./test/resources/River.png", &rgbaData, &rgbaDataLength, &width, &height);
    assert_equal_int(result, 0, "reading RGBA form RGBA PNG file succeeds");
    assert_not_null(rgbaData, "RGBA data from RGBA PNG file");

    // print RGBA bytes array of read PNG image to console
    // bytes_array_dump(rgbaData, rgbaDataLength, width*4);
}

static void run_tests(void) {
    test_is_png_file();
    test_is_not_png_file();
    test_read_RGBA_from_grayscale_PNG_file();
    test_read_RGBA_from_RGBA_PNG_file();
}

test_png_decoding_t test_png_decoding = { .run_tests = run_tests };