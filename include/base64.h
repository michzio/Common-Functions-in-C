//
// Created by Michal Ziobro on 24/09/2016.
//

#ifndef COMMON_FUNCTIONS_BASE64_H
#define COMMON_FUNCTIONS_BASE64_H

#include <stdio.h>

char *base64_encode(const unsigned char *data, const size_t data_len, size_t *base64_len);
unsigned char *base64_decode(const char *base64, const size_t base64_len, size_t *data_len);
// alternative implementation of base64 encoder and decoder
int base64encode(const void* data_buf, size_t dataLength, char* result, size_t resultSize);
int base64decode (char *in, size_t inLen, unsigned char *out, size_t *outLen);


#endif //COMMON_FUNCTIONS_BASE64_H
