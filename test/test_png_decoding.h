//
// Created by Michal Ziobro on 03/10/2016.
//

#ifndef COMMON_FUNCTIONS_TEST_PNG_DECODING_H
#define COMMON_FUNCTIONS_TEST_PNG_DECODING_H

typedef struct {
    void (*run_tests)(void);
} test_png_decoding_t;

extern test_png_decoding_t test_png_decoding;

#endif //COMMON_FUNCTIONS_TEST_PNG_DECODING_H
