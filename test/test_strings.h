//
// Created by Michal Ziobro on 03/10/2016.
//

#ifndef COMMON_FUNCTIONS_TEST_STRINGS_H
#define COMMON_FUNCTIONS_TEST_STRINGS_H

typedef struct {
    void (*run_tests)(void);
} test_strings_t;

extern test_strings_t test_strings;

#endif //COMMON_FUNCTIONS_TEST_STRINGS_H
