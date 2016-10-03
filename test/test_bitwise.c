//
// Created by Michal Ziobro on 03/10/2016.
//

#include <memory.h>
#include <printf.h>
#include "test_bitwise.h"
#include "../bitwise.h"
#include "../../unit_tests/test/assertion.h"

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
    test_bytes_array_dump();
}

test_bitwise_t test_bitwise = { .run_tests = run_tests };