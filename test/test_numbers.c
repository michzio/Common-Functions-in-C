//
// Created by Michal Ziobro on 11/10/2016.
//

#include "test_numbers.h"
#include "../../unit_tests/test/assertion.h"
#include "../numbers.h"

static void test_min(void) {
    assert_equal_int(10, min(10, 20), __func__);
}

static void test_max(void) {
    assert_equal_int(20, max(10, 20), __func__);
}

static void test_range_rand(void) {
    int rand = range_rand(10, 20);
    assert_in_range(rand, 10, 19, __func__);
}

static void run_tests(void) {
    test_min();
    test_max();
    test_range_rand();
}

test_numbers_t test_numbers = { .run_tests = run_tests };