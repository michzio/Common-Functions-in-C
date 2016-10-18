//
// Created by Michal Ziobro on 18/10/2016.
//

#include <ntsid.h>
#include <stdlib.h>
#include <printf.h>
#include "test_lz4.h"
#include "../bitwise.h"
#include "../libraries/lz4/lz4.h"
#include "../../unit_tests/test/assertion.h"
#include "../../unit_tests/common/terminal.h"


static void test_lz4_default_compression(void) {

    unsigned char *data = 0, *compressedData = 0, *decompressedData = 0;
    int dataLength = 0, compressedDataLength = 0, compressionBounds = 0;

    data = fread_binaries("./test/resources/screen1.png", &dataLength);


    // compress data with LZ4
    clock_t beginCompressClock = clock();
    compressionBounds = LZ4_compressBound(dataLength);
    compressedData = malloc(sizeof(unsigned char)*(compressionBounds +1));
    if( (compressedDataLength = LZ4_compress_default(data, compressedData, dataLength, compressionBounds+1)) == 0) {
        fprintf(stderr, "%s: Error at compression of data with LZ4\n", __func__);
        return;
    }
    clock_t endCompressClock = clock();

    double timeSpentCompress = (double)(endCompressClock - beginCompressClock)/CLOCKS_PER_SEC;
    printf(ANSI_COLOR_CYAN "LZ4 compression time was: %f\n" ANSI_COLOR_RESET, timeSpentCompress);

    printf("Data length: %d\n", dataLength);
    printf("Compressed data length: %d\n", compressedDataLength);
    printf(ANSI_COLOR_CYAN "LZ4 compression ratio: %.2f\n" ANSI_COLOR_RESET, ((double) compressedDataLength)/((double) dataLength));

    // decompress data with LZ4
    clock_t beginDecompressClock = clock();
    decompressedData = malloc(sizeof(unsigned char)*dataLength);
    if(LZ4_decompress_safe(compressedData, decompressedData, compressedDataLength, dataLength) < 0){
        fprintf(stderr, "%s: Error at decompression of LZ4 data.\n", __func__);
        return;
    }
    clock_t endDecompressClock = clock();

    double timeSpentDecompress = (double)(endDecompressClock - beginDecompressClock)/CLOCKS_PER_SEC;
    printf(ANSI_COLOR_CYAN "LZ4 decompression time was: %f\n" ANSI_COLOR_RESET, timeSpentDecompress);

    assert_equal_array(data, decompressedData, dataLength, binary_cmp_func, __func__);
}

static void run_tests(void) {
    test_lz4_default_compression();
}

test_lz4_t test_lz4 = { .run_tests = run_tests };
