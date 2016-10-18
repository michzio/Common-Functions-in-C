//
// Created by Michal Ziobro on 27/09/2016.
//

#include <stdlib.h>
#include <printf.h>
#include <sys/stat.h>
#include <string.h>
#include <inttypes.h>
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

/*
static uint64_t next64bitsFromBytesArray(const unsigned char *bytesArray, const int i) {

    uint64_t next64bits = (uint64_t) bytesArray[i+7] | ((uint64_t) bytesArray[i+6] << 8) | ((uint64_t) bytesArray[i+5] << 16) | ((uint64_t) bytesArray[i+4] << 24) | ((uint64_t) bytesArray[i+3] << 32) | ((uint64_t) bytesArray[i+2] << 40) | ((uint64_t) bytesArray[i+1] << 48) | ((uint64_t)bytesArray[i] << 56);
    return next64bits;
}

unsigned char *bitwise_xor64(const unsigned char *A_Bytes_Array, const unsigned char *B_Bytes_Array, const size_t length) {

    unsigned char *XOR_Bytes_Array;

    // allocate XORed bytes array
    XOR_Bytes_Array = malloc(sizeof(unsigned char) * length);

    // perform bitwise XOR operation on bytes arrays A and B using uint64_t
    for(int i=0; i<length; i+=8) {

        uint64_t A_Bytes = next64bitsFromBytesArray(A_Bytes_Array, i);
        uint64_t B_Bytes = next64bitsFromBytesArray(B_Bytes_Array, i);
        uint64_t XOR_Bytes = A_Bytes ^ B_Bytes;
        memcpy(XOR_Bytes_Array + i, &XOR_Bytes, 8);
    }

    return XOR_Bytes_Array;
}
*/

unsigned char *bitwise_xor64(const unsigned char *A_Bytes_Array, const unsigned char *B_Bytes_Array, const size_t length) {

    const uint64_t *aBytes = (const uint64_t *) A_Bytes_Array;
    const uint64_t *bBytes = (const uint64_t *) B_Bytes_Array;

    unsigned char *xorBytes = malloc(sizeof(unsigned char)*length);

    for(int i = 0, j=0; i < length; i +=8, j++) {

        uint64_t aXORbBytes = aBytes[j] ^ bBytes[j];
        //printf("a XOR b = 0x%" PRIx64 "\n", aXORbBytes);

        *((uint64_t*)(xorBytes + i)) = aXORbBytes;
        //memcpy(xorBytes + i, &aXORbBytes, 8);
    }

    return xorBytes;
}

void bytes_array_dump(const unsigned char *Bytes_Array, const size_t length, const size_t row_len) {

    for(int i=0; i<length; i++) {
        printf("%02X ", Bytes_Array[i]);
        if( i % row_len == (row_len-1) ) printf("\n");
    }
}
void bytes_array_dump_segment(const unsigned char *Bytes_Array, const size_t segment_start, const size_t segment_end, const size_t row_len) {

    for(int i=segment_start; i<segment_end; i++) {
        printf("%02X ", Bytes_Array[i]);
        if( (i-segment_start) % row_len == (row_len-1) ) printf("\n");
    }
}

unsigned char *fread_binaries(const char *filePath, size_t *length) {

    unsigned char *bytes_array = 0;
    size_t bytes_array_length = 0;

    // reading bytes from file
    FILE *fp = fopen(filePath, "rb");

    // getting size from file info
    struct stat finfo;
    fstat(fileno(fp), &finfo);
    bytes_array_length = finfo.st_size;

    bytes_array = malloc(sizeof(unsigned char)*bytes_array_length);
    if( fread(bytes_array, 1, bytes_array_length, fp) != bytes_array_length) {
        fprintf(stderr, "%s: Incorrect number of bytes read from file!\n", __func__);
        fclose(fp);
        free(bytes_array);
        if(length) *length = 0;
        return 0;
    }

    fread(NULL, 1, 1, fp);
    if(!feof(fp)) {
        fprintf(stderr, "%s: Not the whole binary file has been read.\n", __func__);
        fclose(fp);
        free(bytes_array);
        if(length) *length = 0;
        return 0;
    }
    fclose(fp);

    if(length) *length = bytes_array_length;
    return bytes_array;
}

int fwrite_binaries(const char *filePath, const unsigned char *bytes_array, const size_t length) {

    // writing bytes to file
    FILE *fp = fopen(filePath, "wb");
    if(fwrite(bytes_array, 1, length, fp) != length) {
        fprintf(stderr, "%s: Not all bytes have been written to the file.\n", __func__);
        fclose(fp);
        return -1;
    }
    fclose(fp);

    return 0;
}