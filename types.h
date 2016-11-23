//
// Created by Michal Ziobro on 31/07/2016.
//

#ifndef COMMON_FUNCTIONS_TYPES_H
#define COMMON_FUNCTIONS_TYPES_H

#include <stdio.h>

typedef enum {
    SUCCESS = 0,
    FAILURE = -1,
    CONTINUE = -2,
    CLOSED = -3,
} result_t;

typedef void *callback_attr_t;
typedef void (*callback_t)(callback_attr_t callback_attr, void *arg);

char *int_to_str(int num, size_t *num_len);
char *uint_to_str(unsigned int num, size_t *num_len);
char *scientific_notation_to_str(double num, size_t  *num_len);
char *float_to_str(float num, size_t *num_len);
char *short_to_str(short num, size_t *num_len);
char *ushort_to_str(unsigned short num, size_t *num_len);
char *long_to_str(long num, size_t *num_len);
char *double_to_str(double num, size_t *num_len);
char *long_double_to_str(long double num, size_t *num_len);
char *ulong_to_str(unsigned long num, size_t *num_len);
char *long_long_to_str(long long num, size_t *num_len);
char *ulong_long_to_str(unsigned long long num, size_t *num_len);
char *octal_to_str(int num, size_t *num_len);
char *hex_to_str(int num, size_t *num_len);
char *pointer_to_str(void *ptr, size_t *ptr_len);
#endif //COMMON_FUNCTIONS_TYPES_H
