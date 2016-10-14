//
// Created by Michal Ziobro on 11/10/2016.
//

#ifndef COMMON_FUNCTIONS_TEST_NUMBERS_H
#define COMMON_FUNCTIONS_TEST_NUMBERS_H

typedef struct {
    void (*run_tests)(void);
} test_numbers_t;

extern test_numbers_t test_numbers;

#endif //COMMON_FUNCTIONS_TEST_NUMBERS_H
