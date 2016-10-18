//
// Created by Michal Ziobro on 04/10/2016.
//

#include "../../../libpng-1.6.24/png.h"

#ifndef COMMON_FUNCTIONS_PNG_HELPER_H
#define COMMON_FUNCTIONS_PNG_HELPER_H

#define PNG_BIT_DEPTH_1 1
#define PNG_BIT_DEPTH_2 2
#define PNG_BIT_DEPTH_4 4
#define PNG_BIT_DEPTH_8 8
#define PNG_BIT_DEPTH_16 16

struct png_buffer {
    png_bytep data;
    png_size_t length;
};
typedef struct png_buffer png_buffer_t;

int getNoOfChannelsForPNGColorType(png_byte png_color_type);

#endif //COMMON_FUNCTIONS_PNG_HELPER_H
