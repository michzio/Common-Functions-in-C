//
// Created by Michal Ziobro on 03/10/2016.
//

#include <memory.h>
#include <printf.h>
#include <stdlib.h>
#include "test_bitwise.h"
#include "../bitwise.h"
#include "../../unit_tests/test/assertion.h"
#include "../../unit_tests/common/terminal.h"

static void test_bitwise_xor(void) {

    // bitwise XOR operation
    char text1[] = "The First  Text";
    char text2[] = "The Second Text";

    unsigned char *xorBytesArray = bitwise_xor((unsigned  char *) text1, (unsigned char *) text2, strlen(text1));

    printf("text1^text2:\n");
    for(int i=0; i<strlen(text1); i++) {
        printf("%02X ", (char) xorBytesArray[i]);
        assert_equal_int(xorBytesArray[i], text1[i]^text2[i], "comparing next byte");
    }
    printf("\n");
}

static void test_bitwise_xor64(void) {

    unsigned char *dataA = 0, *dataB = 0;
    size_t dataALength = 0, dataBLength = 0;

    dataA = fread_binaries("./test/resources/screen1.png", &dataALength);
    dataB = fread_binaries("./test/resources/screen2.png", &dataBLength);

    clock_t beginClock = clock();
    unsigned char *xorData = bitwise_xor64(dataA, dataB, dataALength);
    clock_t endClock = clock();

    //bytes_array_dump(xorData, dataALength, 10);

    fwrite_binaries("/Users/michzio/Desktop/xor_screens.png", xorData, dataALength);

    free(xorData);
    free(dataA);
    free(dataB);

    double timeSpent = (double)(endClock - beginClock)/CLOCKS_PER_SEC;
    printf(ANSI_COLOR_CYAN "XOR execution time was: %f\n" ANSI_COLOR_RESET, timeSpent);
}

static void test_bytes_array_dump(void) {

    // bitwise XOR operation
    char text1[] = "The First  Text";
    char text2[] = "The Second Text";

    unsigned char *xorBytesArray = bitwise_xor((unsigned  char *) text1, (unsigned char *) text2, strlen(text1));

    printf("XOR Bytes Array dumping...\n");
    bytes_array_dump(xorBytesArray, strlen(text1), 10);
    printf("\n");

}

static void run_tests(void) {
    test_bitwise_xor();
    test_bitwise_xor64();
    test_bytes_array_dump();
}

test_bitwise_t test_bitwise = { .run_tests = run_tests };