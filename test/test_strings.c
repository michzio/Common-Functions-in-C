//
// Created by Michal Ziobro on 03/10/2016.
//

#include <stddef.h>
#include <stdio.h>
#include "test_strings.h"
#include "../strings.h"
#include "../../unit_tests/test/assertion.h"
#include "../../unit_tests/common/terminal.h"

static void test_str_split(void) {

    TEST_FUNCTION_HEADER

    char *string = "test1 test2 test3 test4 test5 test6";
    char *delimiter = " ";
    size_t num_tokens = 0;
    char **tokens = str_split(string, delimiter, &num_tokens);

    printf("num_tokens: %lu\n", num_tokens);
    assert_equal_int(num_tokens, 6, "test_str_split - num_tokens");

    for (int i=0; i<num_tokens; i++)
        printf("%s ", tokens[i]);
    printf("\n");

    assert_equal(tokens[0], "test1", str_cmp_func, "test_str_split - 1st token");
    assert_equal(tokens[2], "test3", str_cmp_func, "test_str_split - 3rd token");
    assert_equal(tokens[5], "test6", str_cmp_func, "test_str_split - last token");
}

static void test_str_split_2(void) {

    TEST_FUNCTION_HEADER

    char *string = "delimiter";
    char *delimiter = "delimiter";
    size_t num_tokens = 0;
    char **tokens = str_split(string, delimiter, &num_tokens);

    printf("num_tokens: %lu\n", num_tokens);
    assert_equal_int(num_tokens, 2, "test_str_split_2 - num tokens");

    for (int i=0; i<num_tokens; i++)
        printf("%s ", tokens[i]);
    printf("\n");

    assert_equal(tokens[0], "", str_cmp_func, "test_str_split_2 - 1st token is empty");
    assert_equal(tokens[1], "", str_cmp_func, "test_str_split_2 - last token is empty");
}

static void test_str_split_3(void) {

    TEST_FUNCTION_HEADER

    char *string = "test1delimiter";
    char *delimiter = "delimiter";
    size_t num_tokens = 0;
    char **tokens = str_split(string, delimiter, &num_tokens);

    printf("num_tokens: %lu\n", num_tokens);
    assert_equal_int(num_tokens, 2, "test_str_split_3 - num tokens");

    for (int i=0; i<num_tokens; i++)
        printf("%s ", tokens[i]);
    printf("\n");

    assert_equal(tokens[0], "test1", str_cmp_func, "test_str_split_3 - 1st token is test1");
    assert_equal(tokens[1], "", str_cmp_func, "test_str_split_3 - last token is empty");
}

static void test_str_split_4(void) {

    TEST_FUNCTION_HEADER

    char *string = "delimitertest1";
    char *delimiter = "delimiter";
    size_t num_tokens = 0;
    char **tokens = str_split(string, delimiter, &num_tokens);

    printf("num_tokens: %lu\n", num_tokens);
    assert_equal_int(num_tokens, 2, "test_str_split_4 - num_tokens");

    for (int i=0; i<num_tokens; i++)
        printf("%s ", tokens[i]);
    printf("\n");

    assert_equal(tokens[0], "", str_cmp_func, "test_str_split_4 - 1st token is empty");
    assert_equal(tokens[1], "test1", str_cmp_func, "test_str_split_4 - last token is test1");
}

static void test_str_split_5(void) {

    TEST_FUNCTION_HEADER

    char *string = ""; // empty string i.e. just "\0"
    char *delimiter = "delimiter";
    size_t num_tokens = 0;
    char **tokens = str_split(string, delimiter, &num_tokens);

    printf("num tokens: %lu\n", num_tokens);
    assert_equal_int(num_tokens, 1, "test_str_split_5 - num_tokens");

    for(int i=0; i<num_tokens; i++)
        printf("%s ", tokens[i]);
    printf("\n");

    assert_equal(tokens[0], "", str_cmp_func, "test_str_split_5 - one empty token");
}

static void test_str_split_6(void) {

    TEST_FUNCTION_HEADER

    char *string = "test"; // any text not containing delimiter
    char *delimiter = "delimiter";
    size_t num_tokens = 0;
    char **tokens = str_split(string, delimiter, &num_tokens);

    printf("num tokens: %lu\n", num_tokens);
    assert_equal_int(num_tokens, 1, "test_str_split_6 - num_tokens");

    for(int i=0; i<num_tokens; i++)
        printf("%s ", tokens[i]);
    printf("\n");

    assert_equal(tokens[0], "test", str_cmp_func, "test_str_split_6 - one entire string token");
}

static void run_tests(void) {
    test_str_split();
    test_str_split_2();
    test_str_split_3();
    test_str_split_4();
    test_str_split_5();
    test_str_split_6();
}

test_strings_t test_strings = { .run_tests = run_tests };