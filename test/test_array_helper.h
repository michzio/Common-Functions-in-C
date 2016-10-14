//
// Created by Michal Ziobro on 31/07/2016.
//

#ifndef COMMON_FUNCTIONS_TEST_ARRAY_HELPER_H
#define COMMON_FUNCTIONS_TEST_ARRAY_HELPER_H

typedef struct {
    void (*run_tests)(void);
} test_array_helper_t;

extern test_array_helper_t test_array_helper;

#endif //COMMON_FUNCTIONS_TEST_ARRAY_HELPER_H
