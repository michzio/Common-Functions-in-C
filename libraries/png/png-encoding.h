//
// Created by Michal Ziobro on 30/09/2016.
//

#ifndef COMMON_FUNCTIONS_PNG_H
#define COMMON_FUNCTIONS_PNG_H

#include <ntsid.h>

int saveAsPNGFile(const unsigned char *rgbaData, const size_t width, const size_t height, const char *filePath);

#endif //COMMON_FUNCTIONS_PNG_H
