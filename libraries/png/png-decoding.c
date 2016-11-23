//
// Created by Michal Ziobro on 02/10/2016.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "png-decoding.h"
#include "png-helper.h"

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

// reading from PNG file
int readDataFromPNGFile(const char *filePath, unsigned char **data, size_t *dataLength, size_t *width, size_t *height, unsigned char *bitDepth, unsigned char *colorType) {

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
        fprintf(stderr, "%s: Could not open file for binary reading at given path.\n", __func__);
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

    // read png image header
    png_read_info(png_ptr, info_ptr);
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

    no_of_passes = png_set_interlace_handling(png_ptr);
    png_read_update_info(png_ptr, info_ptr);

    // read png image bytes

    // setup exception handling
    if (setjmp(png_jmpbuf(png_ptr))) {
        fprintf(stderr, "%s: Error during PNG file reading.\n", __func__);
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        return -1;
    }

    // calculate decoded png data sizes
    row_length = (png_width * no_of_channels * png_bit_depth)/CHAR_BIT;
    data_length = png_height * row_length;

    // allocate data structure for storing decoded png data
    *data = malloc(sizeof(unsigned char) * data_length);

    // read png image bytes row by row
    png_byte *png_row = malloc(sizeof(png_byte)*row_length);
    for(int i=0; i<png_height; i++) {
        png_read_row(png_ptr, png_row, NULL);
        /* for(int j=0; j< row_length; j++)
         *   (*data)[i*row_length + j] = png_row[j];
         */
        memcpy(*data + i*row_length, png_row, row_length);
    }
    free(png_row);

    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
    fclose(fp);

    if(dataLength) *dataLength = data_length;
    if(width) *width = png_width;
    if(height) *height = png_height;
    if(colorType) *colorType = png_color_type;
    if(bitDepth) *bitDepth = png_bit_depth;

    return 0;
}

int readRGBAfromPNGFile(const char *filePath, unsigned char **rgbaData, size_t *rgbaDataLength, size_t *width, size_t *height, unsigned char *bitDepth) {

    unsigned char rgbaColorType = PNG_COLOR_TYPE_RGB_ALPHA;
    return readDataFromPNGFile(filePath, rgbaData, rgbaDataLength, width, height, bitDepth, &rgbaColorType);
}

extern int readRGBfromPNGFile(const char *filePath, unsigned char **rgbData, size_t *rgbDataLength, size_t *width, size_t *height, unsigned char *bitDepth) {

    unsigned char rgbColorType = PNG_COLOR_TYPE_RGB;
    return readDataFromPNGFile(filePath, rgbData, rgbDataLength, width, height, bitDepth, &rgbColorType);
}

int readGrayscaleAlphaFromPNGFile(const char *filePath, unsigned char **gaData, size_t *gaDataLength, size_t *width, size_t *height, unsigned char *bitDepth) {

    unsigned char grayscaleAlphaColorType = PNG_COLOR_TYPE_GRAY_ALPHA;
    return readDataFromPNGFile(filePath, gaData, gaDataLength, width, height, bitDepth, &grayscaleAlphaColorType);
}

int readGrayscaleFromPNGFile(const char *filePath, unsigned char **gData, size_t *gDataLength, size_t *width, size_t *height, unsigned char *bitDepth) {

    unsigned char grayscaleColorType = PNG_COLOR_TYPE_GRAY;
    return readDataFromPNGFile(filePath, gData, gDataLength, width, height, bitDepth, &grayscaleColorType);
}

// reading from PNG buffer
void read_png_data_callback(png_structp png_ptr, png_bytep png_data, png_size_t png_data_length) {

    png_buffer_t *png_buffer = (png_buffer_t *) png_get_io_ptr(png_ptr);

    if(png_data_length > png_buffer->length) {
            fprintf(stderr, "%s: Could not supply requested number of png data.\n", __func__);
            png_error(png_ptr, "EOF");
    }

    // copy png data from png buffer
    memcpy(png_data, png_buffer->data, png_data_length);
    png_buffer->data += png_data_length;
    png_buffer->length -= png_data_length;
}


int readDataFromPNGBuffer(const unsigned char *pngData, const size_t pngDataLength, unsigned char **data, size_t *dataLength, size_t *width, size_t *height, unsigned char *bitDepth, unsigned char *colorType) {

    png_structp png_ptr = 0;
    png_infop info_ptr = 0;
    png_buffer_t png_buffer;
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
    if(setjmp(png_jmpbuf(png_ptr))) {
        fprintf(stderr, "%s: Error during PNG buffer IO.\n", __func__);
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        return -1;
    }

    // initialize png buffer fields with png data to be decoded
    png_buffer.data = pngData;
    png_buffer.length = pngDataLength;

    // set png read callback
    png_set_read_fn(png_ptr, &png_buffer, read_png_data_callback);

    // read png image header
    png_read_info(png_ptr, info_ptr);
    png_width = png_get_image_width(png_ptr, info_ptr);
    png_height = png_get_image_height(png_ptr, info_ptr);
    png_color_type = png_get_color_type(png_ptr, info_ptr);
    png_bit_depth = png_get_bit_depth(png_ptr, info_ptr);

    // check whether PNG color type is correct
    if(colorType && png_color_type != *colorType) {
        fprintf(stderr, "%s: PNG buffer has incorrect color type defined.\n", __func__);
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        return -1;
    }

    // check whether PNG bit depth is correct
    if(bitDepth && png_bit_depth != *bitDepth) {
        fprintf(stderr, "%s: PNG buffer has incorrect bit depth defined.\n", __func__);
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        return -1;
    }

    no_of_channels = getNoOfChannelsForPNGColorType(png_color_type);

    no_of_passes = png_set_interlace_handling(png_ptr);
    png_read_update_info(png_ptr, info_ptr);

    // read png image bytes

    // setup exception handling
    if(setjmp(png_jmpbuf(png_ptr))) {
        fprintf(stderr, "%s: Error during PNG buffer reading.\n", __func__);
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        return -1;
    }

    // calculate decoded png data sizes
    row_length = (png_width * no_of_channels * png_bit_depth)/CHAR_BIT;
    data_length = png_height * row_length;

    // allocate data structure for storing decoded png data
    *data = malloc(sizeof(unsigned char) * data_length);

    // read png image bytes row by row
    png_byte *png_row = malloc(sizeof(png_byte)*row_length);
    for(int i=0; i<png_height; i++) {
        png_read_row(png_ptr, png_row, NULL);
        memcpy(*data + i*row_length, png_row, row_length);
    }
    free(png_row);

    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

    if(dataLength) *dataLength = data_length;
    if(width) *width = png_width;
    if(height) *height = png_height;
    if(colorType) *colorType = png_color_type;
    if(bitDepth) *bitDepth = png_bit_depth;

    return 0;
}

int readRGBAfromPNGBuffer(const unsigned char *pngData, const size_t pngDataLength, unsigned char **rgbaData, size_t *rgbaDataLength, size_t *width, size_t *height, unsigned char *bitDepth) {

    unsigned char rgbaColorType = PNG_COLOR_TYPE_RGB_ALPHA;
    return readDataFromPNGBuffer(pngData, pngDataLength, rgbaData, rgbaDataLength, width, height, bitDepth, &rgbaColorType);
}

int readRGBfromPNGBuffer(const unsigned char *pngData, const size_t pngDataLength, unsigned char **rgbData, size_t *rgbDataLength, size_t *width, size_t *height, unsigned char *bitDepth) {

    unsigned char rgbColorType = PNG_COLOR_TYPE_RGB;
    return readDataFromPNGBuffer(pngData, pngDataLength, rgbData, rgbDataLength, width, height, bitDepth, &rgbColorType);
}

int readGrayscaleAlphaFromPNGBuffer(const unsigned char *pngData, const size_t pngDataLength, unsigned char **gaData, size_t *gaDataLength, size_t *width, size_t *height, unsigned char *bitDepth) {

    unsigned char grayscaleAlphaColorType = PNG_COLOR_TYPE_GRAY_ALPHA;
    return readDataFromPNGBuffer(pngData, pngDataLength, gaData, gaDataLength, width, height, bitDepth, &grayscaleAlphaColorType);
}

int readGrayscaleFromPNGBuffer(const unsigned char *pngData, const size_t pngDataLength, unsigned char **gData, size_t *gDataLength, size_t *width, size_t *height, unsigned char *bitDepth) {

    unsigned char grayscaleColorType = PNG_COLOR_TYPE_GRAY;
    return readDataFromPNGBuffer(pngData, pngDataLength, gData, gDataLength, width, height, bitDepth, grayscaleColorType);
}
