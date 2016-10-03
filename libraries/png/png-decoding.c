//
// Created by Michal Ziobro on 02/10/2016.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "png-decoding.h"
#include "../../../libpng-1.6.24/png.h"

#define PNG_BIT_DEPTH_1 1
#define PNG_BIT_DEPTH_2 2
#define PNG_BIT_DEPTH_4 4
#define PNG_BIT_DEPTH_8 8
#define PNG_BIT_DEPTH_16 16

static int getNoOfChannelsForPNGColorType(png_byte png_color_type) {

    int no_of_channels = 0;

    switch(png_color_type) {
        case PNG_COLOR_TYPE_PALETTE:
        case PNG_COLOR_TYPE_GRAY: {
            no_of_channels = 1;
            break;
        }
        case PNG_COLOR_TYPE_GRAY_ALPHA: {
            no_of_channels = 2;
            break;
        }
        case PNG_COLOR_TYPE_RGB: {
            no_of_channels = 3;
            break;
        }
        case PNG_COLOR_TYPE_RGB_ALPHA: {
            no_of_channels = 4;
            break;
        }
    }

    return no_of_channels;
}

bool isPNGFile(const char *filePath) {

    FILE *fp = fopen(filePath, "rb");
    if(!fp) {
        fprintf(stderr, "%s: Could not open file under given file path.\n", __func__);
        return false;
    }

    int header_length = 8;
    png_byte header[header_length];

    if(fread(header, 1, header_length, fp) != header_length) {
        fprintf(stderr, "%s: Could not read header of PNG file.\n", __func__);
        return false;
    }

    fclose(fp);

    int isPNG = !png_sig_cmp(header, 0, header_length);
    if(!isPNG) {
        fprintf(stderr, "%s: file is not PNG file.\n", __func__);
        return false;
    }

    return isPNG;
}

int readDataFromPNGFile(const char *filePath, unsigned char **data, size_t *dataLength, size_t *width, size_t *height, unsigned char *colorType, unsigned char *bitDepth) {

    png_structp png_ptr = 0;
    png_infop info_ptr = 0;
    png_uint_32 png_width = 0;
    png_uint_32 png_height = 0;
    png_byte png_color_type;
    png_byte png_bit_depth;
    int no_of_passes = 0;
    size_t data_length = 0;
    size_t row_length = 0;
    int no_of_channels = 0;

    // initialize PNG read structure
    if( (png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL)) == NULL ) {
        fprintf(stderr, "%s: Could not allocate png read struct.\n", __func__);
        return -1;
    }

    // initialize PNG info structure
    if( (info_ptr = png_create_info_struct(png_ptr)) == NULL ) {
        fprintf(stderr, "%s: Could not allocate png info struct.\n", __func__);
        png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
        return -1;
    }

    // setup exception handling
    if (setjmp(png_jmpbuf(png_ptr))) {
        fprintf(stderr, "%s: Error during PNG file IO.\n", __func__);
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        return -1;
    }

    // get file descriptor to file under given path
    FILE *fp = fopen(filePath, "rb");
    if(!fp) {
        fprintf(stderr, "%s: Could not open file under given file path.\n", __func__);
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        return -1;
    }

    // initializing png read struct with png file descriptor
    png_init_io(png_ptr, fp);

    // need to be set if on given file stream has been already read any signature bytes
    // png_set_sig_bytes(png_ptr, number);

    // default compression buffer size is 8192 bytes
    // png_set_compression_buffer_size(png_ptr, buffer_size);

    // CRC errors to be handled in a different manner set
    // png_set_crc_action(png_ptr, crit_action, ancil_action);

    // set callback called after each PNG file row has been read
    // png_set_read_status_fn(png_ptr, read_row_callback);

    png_read_info(png_ptr, info_ptr);

    // get png image size (width, height)
    png_width = png_get_image_width(png_ptr, info_ptr);
    png_height = png_get_image_height(png_ptr, info_ptr);

    png_color_type = png_get_color_type(png_ptr, info_ptr);
    png_bit_depth = png_get_bit_depth(png_ptr, info_ptr);

    // check whether PNG color type is correct
    if(colorType && png_color_type != *colorType) {
        fprintf(stderr, "%s: PNG file has incorrect color type defined.\n", __func__);
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        return -1;
    }

    // check whether PNG bit depth is correct
    if(bitDepth && png_bit_depth != *bitDepth) {
        fprintf(stderr, "%s: PNG file has incorrect bit depth defined.\n", __func__);
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        return -1;
    }

    no_of_channels = getNoOfChannelsForPNGColorType(png_color_type);

    // read PNG image
    no_of_passes = png_set_interlace_handling(png_ptr);
    png_read_update_info(png_ptr, info_ptr);

    // setup exception handling
    if (setjmp(png_jmpbuf(png_ptr))) {
        fprintf(stderr, "%s: Error during PNG file reading.\n", __func__);
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        return -1;
    }

    // calculate decoded png data sizes
    row_length = (png_width * no_of_channels * png_bit_depth)/CHAR_BIT;
    data_length = png_height * row_length;

    // allocate data structure for storing png data
    *data = malloc(sizeof(unsigned char) *data_length);

    // read png image row by row
    png_byte *png_row = malloc(sizeof(png_byte)*row_length);
    for(int i = 0; i<png_height; i++) {
        png_read_row(png_ptr, png_row, NULL);
        /* for(int j=0; j< row_length; j++)
         *   (*data)[i*row_length + j] = png_row[j];
         */
        memcpy(*data + i*row_length, png_row, row_length);
    }
    free(png_row);
    fclose(fp);

    if(dataLength) *dataLength = data_length;
    if(width) *width = png_width;
    if(height) *height = png_height;
    if(colorType) *colorType = png_color_type;
    if(bitDepth) *bitDepth = png_bit_depth;

    return 0;
}

int readRGBAFromPNGFile(const char *filePath, unsigned char **rgbaData, size_t *rgbaDataLength, size_t *width, size_t *height) {

    unsigned char rgbaColorType = PNG_COLOR_TYPE_RGB_ALPHA;
    return readDataFromPNGFile(filePath, rgbaData, rgbaDataLength, width, height, &rgbaColorType, NULL);
}