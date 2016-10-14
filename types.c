//
// Created by Michal Ziobro on 14/08/2016.
//

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "types.h"

char *int_to_str(int num, size_t *num_len) {

    char *str;
    size_t len;

    len = snprintf(NULL, 0, "%d", num);
    str = malloc((len+1)*sizeof(char));

    sprintf(str, "%d", num);
    if(num_len != NULL) *num_len = len;
    return str;
}

char *uint_to_str(unsigned int num, size_t *num_len) {

    char *str;
    size_t len;

    len = snprintf(NULL, 0, "%u", num);
    str = malloc((len+1)*sizeof(char));

    sprintf(str, "%u", num);
    if(num_len != NULL) *num_len = len;
    return str;
}

char *scientific_notation_to_str(double num, size_t  *num_len) {

    char *str;
    size_t len;

    len = snprintf(NULL, 0, "%e", num);
    str = malloc((len+1)*sizeof(char));

    sprintf(str, "%e", num);
    if(num_len != NULL) *num_len = len;
    return str;
}

char *float_to_str(float num, size_t *num_len) {

    char *str;
    size_t len;

    len = snprintf(NULL, 0, "%f", num);
    str = malloc((len+1)*sizeof(char));

    sprintf(str, "%f", num);
    if(num_len != NULL) *num_len = len;
    return str;
}

char *short_to_str(short num, size_t *num_len) {

    char *str;
    size_t len;

    len = snprintf(NULL, 0, "%hi", num);
    str = malloc((len+1)*sizeof(char));

    sprintf(str, "%hi", num);
    if(num_len != NULL) *num_len = len;
    return str;
}

char *ushort_to_str(unsigned short num, size_t *num_len) {

    char *str;
    size_t len;

    len = snprintf(NULL, 0, "%hu", num);
    str = malloc((len+1)*sizeof(char));

    sprintf(str, "%hu", num);
    if(num_len != NULL) *num_len = len;
    return str;
}

char *long_to_str(long num, size_t *num_len) {

    char *str;
    size_t len;

    len = snprintf(NULL, 0, "%ld", num);
    str = malloc((len+1)*sizeof(char));

    sprintf(str, "%ld", num);
    if(num_len != NULL) *num_len = len;
    return str;
}

char *double_to_str(double num, size_t *num_len) {

    char *str;
    size_t len;

    len = snprintf(NULL, 0, "%lf", num);
    str = malloc((len+1)*sizeof(char));

    sprintf(str, "%lf", num);
    if(num_len != NULL) *num_len = len;
    return str;
}

char *long_double_to_str(long double num, size_t *num_len) {

    char *str;
    size_t len;

    len = snprintf(NULL, 0, "%Lf", num);
    str = malloc((len+1)*sizeof(char));

    sprintf(str, "%Lf", num);
    if(num_len != NULL) *num_len = len;
    return str;
}

char *ulong_to_str(unsigned long num, size_t *num_len) {

    char *str;
    size_t len;

    len = snprintf(NULL, 0, "%lu", num);
    str = malloc((len+1)*sizeof(char));

    sprintf(str, "%lu", num);
    if(num_len != NULL) *num_len = len;
    return str;
}

char *long_long_to_str(long long num, size_t *num_len) {

    char *str;
    size_t len;

    len = snprintf(NULL, 0, "%lld", num);
    str = malloc((len+1)*sizeof(char));

    sprintf(str, "%lld", num);
    if(num_len != NULL) *num_len = len;
    return str;
}

char *ulong_long_to_str(unsigned long long num, size_t *num_len) {

    char *str;
    size_t len;

    len = snprintf(NULL, 0, "%llu", num);
    str = malloc((len+1)*sizeof(char));

    sprintf(str, "%llu", num);
    if(num_len != NULL) *num_len = len;
    return str;
}

char *octal_to_str(int num, size_t *num_len) {

    char *str;
    size_t len;

    len = snprintf(NULL, 0, "%s%o", (num<0)?"-":"", (num<0)?-num:num);
    str = malloc((len+1)*sizeof(char));

    sprintf(str, "%s%o", (num<0)?"-":"",(num<0)?-num:num);
    if(num_len != NULL) *num_len = len;
    return str;
}

char *hex_to_str(int num, size_t *num_len) {

    char *str;
    size_t len;

    len = snprintf(NULL, 0, "%s%x", (num<0)?"-":"",(num<0)?-num:num);
    str = malloc((len+1)*sizeof(char));

    sprintf(str, "%s%x", (num<0)?"-":"",(num<0)?-num:num);
    if(num_len != NULL) *num_len = len;
    return str;
}

char *pointer_to_str(void *ptr, size_t *ptr_len) {

    char *str;
    size_t len;

    len = snprintf(NULL, 0, "%p", ptr);
    str = malloc((len+1)*sizeof(char));

    sprintf(str, "%p", ptr);
    if(ptr_len != NULL) *ptr_len = len;
    return str;
}