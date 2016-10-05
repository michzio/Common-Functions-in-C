//
// Created by Michal Ziobro on 04/10/2016.
//

#ifndef COMMON_FUNCTIONS_TEST_PNG_ENCODING_H
#define COMMON_FUNCTIONS_TEST_PNG_ENCODING_H

typedef struct {
    void (*run_tests)(void);
} test_png_encoding_t;

extern test_png_encoding_t test_png_encoding;

#endif //COMMON_FUNCTIONS_TEST_PNG_ENCODING_H
