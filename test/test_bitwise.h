//
// Created by Michal Ziobro on 03/10/2016.
//

#ifndef COMMON_FUNCTIONS_TEST_BITWISE_H
#define COMMON_FUNCTIONS_TEST_BITWISE_H

typedef struct {
    void (*run_tests)(void);
} test_bitwise_t;

extern test_bitwise_t test_bitwise;

#endif //COMMON_FUNCTIONS_TEST_BITWISE_H
