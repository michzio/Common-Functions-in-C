//
// Created by Michal Ziobro on 03/10/2016.
//

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include "test_md5.h"
#include "../libraries/md5/md5.h"
#include "../../comparers/comparer.h"
#include "../../unit_tests/test/assertion.h"

static void test_md5_hash(void) {

    char *str_data = "Some data to MD5";
    char *md5  = md5_hash(str_data, strlen(str_data));
    printf("md5: %s\n", md5);
    assert_equal(md5, "bf7d182196e6f9d829f5ac74c15f2d92", str_cmp_func, __func__);
    free(md5);

}

static void run_tests(void) {
    test_md5_hash();
}

test_md5_t test_md5 = { .run_tests = run_tests };