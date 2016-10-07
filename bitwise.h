//
// Created by Michal Ziobro on 27/09/2016.
//

#ifndef COMMON_FUNCTIONS_BITWISE_H
#define COMMON_FUNCTIONS_BITWISE_H

#include <ntsid.h>

unsigned char *bitwise_xor(const unsigned char *A_Bytes_Array, const unsigned char *B_Bytes_Array, const size_t length);
unsigned char *bitwise_abs_diff(const unsigned char *A_Bytes_Array, const unsigned char *B_Bytes_Array, const size_t length);
void bytes_array_dump(const unsigned char *Bytes_Array, const size_t length, const size_t row_len);
unsigned char *fread_binaries(const char *filePath, size_t *length);
int fwrite_binaries(const char *filePath, const unsigned char *bytes_array, const size_t length);

#endif //COMMON_FUNCTIONS_BITWISE_H
