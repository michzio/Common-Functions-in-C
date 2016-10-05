//
// Created by Michal Ziobro on 30/09/2016.
//

#include <stdio.h>
#include "../../../libpng-1.6.24/png.h"
#include "png-encoding.h"
#include "png-helper.h"

int writeDataAsPNGFile(const unsigned char *data, const size_t width, const size_t height, const int bitDepth, const int colorType, const char *filePath) {

    png_structp png_ptr = 0;
    png_infop info_ptr = 0;
    size_t row_length = 0;
    int no_of_channels = 0;

    // initialize PNG write structure
    if( (png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL)) == NULL ) {
        fprintf(stderr, "%s: Could not allocate png write struct.\n", __func__);
        return -1;
    }

    // initialize PNG info structure
    if( (info_ptr = png_create_info_struct(png_ptr)) == NULL ) {
        fprintf(stderr, "%s: Could not allocate png info struct.\n", __func__);
        png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
        return -1;
    }

    // setup exception handling
    if (setjmp(png_jmpbuf(png_ptr))) {
        fprintf(stderr, "%s: Error during PNG file IO.\n", __func__);
        png_destroy_write_struct(&png_ptr, &info_ptr);
        return -1;
    }

    FILE *fp = fopen(filePath, "wb");
    if(!fp) {
        fprintf(stderr, "%s: Could not open file for binary writing at given path.\n", __func__);
        png_destroy_write_struct(&png_ptr, &info_ptr);
        return -1;
    }

    // initialize png write struct with png file descriptor
    png_init_io(png_ptr, fp);

    // write png image header
    if (setjmp(png_jmpbuf(png_ptr))) {
        fprintf(stderr, "%s: Error during writing PNG header.\n", __func__);
        png_destroy_write_struct(&png_ptr, &info_ptr);
        fclose(fp);
        return -1;
    }

    png_set_IHDR(png_ptr, info_ptr, width, height, bitDepth, colorType,
                 PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    png_write_info(png_ptr, info_ptr);

    // write png image bytes
    if (setjmp(png_jmpbuf(png_ptr))) {
        fprintf(stderr, "%s: Error during writing PNG bytes.\n", __func__);
        png_destroy_write_struct(&png_ptr, &info_ptr);
        fclose(fp);
        return -1;
    }

    no_of_channels = getNoOfChannelsForPNGColorType(colorType);
    row_length = (width * no_of_channels * bitDepth)/CHAR_BIT;

    // write png image bytes row by row
    for(int i = 0; i<height; i++) {
        png_write_row(png_ptr, data + i*row_length);
    }

    // write png image end
    if (setjmp(png_jmpbuf(png_ptr))) {
        fprintf(stderr, "%s: Error during writing PNG end.\n", __func__);
        png_destroy_write_struct(&png_ptr, &info_ptr);
        fclose(fp);
        return -1;
    }

    png_write_end(png_ptr, NULL);

    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);

    return 0;
}

int writeRGBAasPNGFile(const unsigned char *rgbaData, const size_t width, const size_t height, const int bitDepth, const char *filePath) {
    return writeDataAsPNGFile(rgbaData, width, height, bitDepth, PNG_COLOR_TYPE_RGB_ALPHA, filePath);
}

int writeRGBasPNGFile(const unsigned char *rgbData, const size_t width, const size_t height, const int bitDepth, const char *filePath) {
    return writeDataAsPNGFile(rgbData, width, height, bitDepth, PNG_COLOR_TYPE_RGB, filePath);
}

int writeGrayscaleAlphaAsPNGFile(const unsigned char *gaData, const size_t width, const size_t height, const int bitDepth, const char *filePath) {
    return writeDataAsPNGFile(gaData, width, height, bitDepth, PNG_COLOR_TYPE_GRAY_ALPHA, filePath);
}

int writeGrayscaleAsPNGFile(const unsigned char *gData, const size_t width, const size_t height, const int bitDepth, const char *filePath) {
    return writeDataAsPNGFile(gData, width, height, bitDepth, PNG_COLOR_TYPE_GRAY, filePath);
}