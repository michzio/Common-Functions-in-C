//
// Created by Michal Ziobro on 06/10/2016.
//

#ifndef COMMON_FUNCTIONS_TEST_OPENCV_H
#define COMMON_FUNCTIONS_TEST_OPENCV_H

typedef struct {
    void (*run_tests)(void);
} test_opencv_t;

extern test_opencv_t test_opencv;

#endif //COMMON_FUNCTIONS_TEST_OPENCV_H
