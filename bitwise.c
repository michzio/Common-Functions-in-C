//
// Created by Michal Ziobro on 27/09/2016.
//

#include <stdlib.h>
#include <printf.h>
#include <sys/stat.h>
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