//
// Created by Michal Ziobro on 18/10/2016.
//

#ifndef COMMON_FUNCTIONS_TEST_LZ4_H
#define COMMON_FUNCTIONS_TEST_LZ4_H

typedef struct {
    void (*run_tests)(void);
} test_lz4_t;

extern test_lz4_t test_lz4;

#endif //COMMON_FUNCTIONS_TEST_LZ4_H
