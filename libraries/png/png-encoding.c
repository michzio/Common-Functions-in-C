//
// Created by Michal Ziobro on 30/09/2016.
//

#include <stdio.h>
#include "../../../libpng-1.6.24/png.h"
#include "png-encoding.h"

int saveAsPNGFile(const unsigned char *rgbaData, const size_t width, const size_t height, const char *filePath) {

    FILE *fp = fopen(filePath, "wb");
    png_structp pngPtr = 0;


}