#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "strings.h"
#include "base64.h"
#include "bitwise.h"
#include "libraries/md5/md5.h"
#include "libraries/png/png-decoding.h"
#include "test/test_png_decoding.h"
#include "test/test_strings.h"
#include "test/test_bitwise.h"
#include "test/test_md5.h"
#include "test/test_png_encoding.h"
#include "test/test_opencv.h"
#include "test/test_numbers.h"
#include "test/test_array_helper.h"
#include "test/test_lz4.h"

int main(void) {

    printf("Common Functions Library.\n");

    /*
    char *data = "The above implementation is best with a language like JavaScript that handles string concatenation of arbitrary length strings very efficiently. Other languages (e.g. C) will work much more efficiently by allocating memory for a new string/array of the appropriate size (the output string length is easily calculated from the input string at the very beginning) and then simply setting each character index, as opposed to concatenation.";
    printf("data: %s\n", data);

    size_t base64_len = 0;
    char *base64 = malloc(256);
    base64encode(data, strlen(data), base64, 256);
    printf("base64: %s\n", base64);

    base64 = base64_encode(data, strlen(data), &base64_len);
    printf("base64 - 2: %s\n", base64);

    size_t decoded_data_len = 0;
    unsigned char * decoded_data = base64_decode(base64, base64_len, &decoded_data_len);
    printf("decoded data: %s\n", decoded_data);
     */

    test_bitwise.run_tests();
    test_strings.run_tests();
    test_numbers.run_tests();
    //test_array_helper.run_tests();
    //test_md5.run_tests();
    //test_png_decoding.run_tests();
    //test_png_encoding.run_tests();
    //test_opencv.run_tests();
    //test_lz4.run_tests();

    return 0;
}