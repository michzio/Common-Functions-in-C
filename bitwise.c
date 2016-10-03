//
// Created by Michal Ziobro on 27/09/2016.
//

#include <stdlib.h>
#include <printf.h>
#include "bitwise.h"

unsigned char *bitwise_xor(const unsigned char *A_Bytes_Array, const unsigned char *B_Bytes_Array, const size_t length) {

    unsigned char *XOR_Bytes_Array;

    // allocate XORed bytes array
    XOR_Bytes_Array = malloc(sizeof(unsigned char) * length);

    // perform bitwise XOR operation on bytes arrays A and B
    for(int i=0; i < length; i++)
        XOR_Bytes_Array[i] = (unsigned char)(A_Bytes_Array[i] ^ B_Bytes_Array[i]);

    return XOR_Bytes_Array;
}

void bytes_array_dump(const unsigned char *Bytes_Array, const size_t length, const size_t row_len) {

    for(int i=0; i<length; i++) {
        printf("%02X ", Bytes_Array[i]);
        if(i % row_len == 0) printf("\n");
    }
}