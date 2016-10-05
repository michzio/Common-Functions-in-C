//
// Created by Michal Ziobro on 04/10/2016.
//

#include "png-helper.h"

int getNoOfChannelsForPNGColorType(png_byte png_color_type) {

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