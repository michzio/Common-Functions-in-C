//
// Created by Michal Ziobro on 03/10/2016.
//

#ifndef COMMON_FUNCTIONS_TEST_MD5_H
#define COMMON_FUNCTIONS_TEST_MD5_H

typedef struct {
    void (*run_tests)(void);
} test_md5_t;

extern test_md5_t test_md5;

#endif //COMMON_FUNCTIONS_TEST_MD5_H
