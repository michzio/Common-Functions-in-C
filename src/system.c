//
// Created by Michal Ziobro on 13/08/2016.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "../include/system.h"
#include "../include/types.h"

#define BUF_SIZE 256

char *exec_cmd(const char *cmd) {

    char buf[BUF_SIZE];
    char *result;
    FILE *pipe;

    printf("exec_cmd: %s\n", cmd);

    result = malloc(sizeof(char)*BUF_SIZE);

    if((pipe = popen(cmd, "r")) == NULL) {
        fprintf(stderr, "popen: failed!\n");
        return NULL;
    }

    while(!feof(pipe)) {
        if(fgets(buf, BUF_SIZE, pipe) != NULL) {
            //printf("new len: %d vs old len: %d\n", strlen(result)+strlen(buf), strlen(buf));
            result = realloc(result, (strlen(result)+strlen(buf))* sizeof(char) );
            strcat(result, buf);
        }
    }

    if(pclose(pipe) < 0)  {
        printf("pclose: failed!\n");
        return NULL;
    }

    return result;
}

/**
 * private function used as the helper while
 * invoking exec_cmd() from exec_cmd_f() that
 * enable proper deallocation of cmd string.
 */
static char *exec_cmd_helper(char *cmd) {

    char *result;
    result = exec_cmd(cmd);
    free(cmd); // deallocate cmd string
    return result;
}

char *exec_cmd_f(const char *cmd_format,...) {

    const char *traverse;
    char *cmd;
    size_t cmd_len = 0;

    va_list va_list;
    int i;
    unsigned int ui;
    long l;
    unsigned long ul;
    long long ll;
    unsigned long long ull;
    double d;
    long double ld;
    float f;
    char c;
    void *p;
    char *str;
    size_t str_len = 0;

    cmd = malloc(sizeof(char)*1);
    // initialize va_list
    va_start(va_list, cmd_format);

    // parse cmd_format argument using traverse helper variable
    for(traverse = cmd_format; *traverse != '\0'; traverse++) {

        if( *traverse != '%' ) {
            // copy next char of cmd format to cmd cmd string
            strncpy(cmd + cmd_len++, traverse, 1);
            cmd = realloc(cmd, sizeof(char)*(cmd_len+1));
            continue;
        }

        // get format specifier after % sign
        traverse++;
        switch (*traverse)
        {
            case 'c':   // char format specifier
                c = va_arg(va_list, int);
                strncpy(cmd + cmd_len++, &c, 1);
                cmd = realloc(cmd, sizeof(char)*(cmd_len+1));
                break;
            case 'd':   // signed integer format specifier
                i = va_arg(va_list, int);
                str = int_to_str(i, &str_len);
                cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                strncpy(cmd + cmd_len, str, str_len);
                cmd_len += str_len;
                break;
            case 'e':
            case 'E':   // scientific notation of float/double format specifier
                d = va_arg(va_list, double);
                str = scientific_notation_to_str(d, &str_len);
                cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                strncpy(cmd + cmd_len, str, str_len);
                cmd_len += str_len;
                break;
            case 'f':   // float format specifier
                f = va_arg(va_list, double);
                str = float_to_str(f, &str_len);
                cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                strncpy(cmd + cmd_len, str, str_len);
                cmd_len += str_len;
                break;
            case 'g':
            case 'G':   // similar to %e or %E format specifier
                d = va_arg(va_list, double);
                str = scientific_notation_to_str(d, &str_len);
                cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                strncpy(cmd + cmd_len, str, str_len);
                cmd_len += str_len;
                break;
            case 'h':   // check further format specifier
                if(strncmp(traverse, "hi", 2) == 0) {
                        // short format specifier
                    i = va_arg(va_list, int);
                    str = short_to_str(i, &str_len);
                    cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                    strncpy(cmd + cmd_len, str, str_len);
                    cmd_len += str_len;
                    traverse++;
                } else if(strncmp(traverse, "hu", 2) == 0) {
                        // unsigned short format specifier
                    i = va_arg(va_list, int);
                    str = ushort_to_str(i, &str_len);
                    cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                    strncpy(cmd + cmd_len, str, str_len);
                    cmd_len += str_len;
                    traverse++;
                }
                break;
            case 'i':   // signed integer format specifier
                i = va_arg(va_list, int);
                str = int_to_str(i, &str_len);
                cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                strncpy(cmd + cmd_len, str, str_len);
                cmd_len += str_len;
                break;
            case 'l':   // check further format specifier
                if(strncmp(traverse, "ld", 2) == 0 || strncmp(traverse, "li", 2) == 0) {
                        // long format specifier
                    l = va_arg(va_list, long);
                    str = long_to_str(l, &str_len);
                    cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                    strncpy(cmd + cmd_len, str, str_len);
                    cmd_len += str_len;
                    traverse++;
                } else if(strncmp(traverse, "lf", 2) == 0) {
                        // double format specifier
                    d = va_arg(va_list, double);
                    str = double_to_str(d, &str_len);
                    cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                    strncpy(cmd + cmd_len, str, str_len);
                    cmd_len += str_len;
                    traverse++;
                } else if(strncmp(traverse, "lu", 2) == 0) {
                        // unsigned long format specifier
                    ul = va_arg(va_list, unsigned long);
                    str = ulong_to_str(ul, &str_len);
                    cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                    strncpy(cmd + cmd_len, str, str_len);
                    cmd_len += str_len;
                    traverse++;
                } else if(strncmp(traverse, "lld", 3) == 0 || strncmp(traverse, "lli", 3) == 0) {
                        // long long format specifier
                    ll = va_arg(va_list, long long);
                    str = long_long_to_str(ll, &str_len);
                    cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                    strncpy(cmd + cmd_len, str, str_len);
                    cmd_len += str_len;
                    traverse +=2;
                } else if(strncmp(traverse, "llu", 3) == 0) {
                        // unsigned long long format specifier
                    ull = va_arg(va_list, unsigned long long);
                    str = ulong_long_to_str(ull, &str_len);
                    cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                    strncpy(cmd + cmd_len, str, str_len);
                    cmd_len += str_len;
                    traverse +=2;
                } else {
                        // long format specifier, just "%l"
                    l = va_arg(va_list, long);
                    str = long_to_str(l, &str_len);
                    cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                    strncpy(cmd + cmd_len, str, str_len);
                    cmd_len += str_len;
                }
                break;
            case 'L':   // check further format specifier
                if(strncmp(traverse, "Lf", 2) == 0) {
                        // long double format specifier
                    ld = va_arg(va_list, long double);
                    str = long_double_to_str(ld, &str_len);
                    cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                    strncpy(cmd + cmd_len, str, str_len);
                    cmd_len += str_len;
                    traverse++;
                }
                break;
            case 'o':   // octal format specifier
                i = va_arg(va_list, int);
                str = octal_to_str(i, &str_len);
                cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                strncpy(cmd + cmd_len, str, str_len);
                cmd_len += str_len;
                break;
            case 'p':    // void pointer format specifier
                p = va_arg(va_list, void *);
                str = pointer_to_str(p, &str_len);
                cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                strncpy(cmd + cmd_len, str, str_len);
                cmd_len += str_len;
                break;
            case 's':    // string format specifier
                str = va_arg(va_list, char *);
                str_len = strlen(str);
                cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                strncpy(cmd + cmd_len, str, str_len);
                cmd_len += str_len;
                break;
            case 'u':    // unsigned integer format specifier
                ui = va_arg(va_list, unsigned int);
                str = uint_to_str(ui, &str_len);
                cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                strncpy(cmd + cmd_len, str, str_len);
                cmd_len += str_len;
                break;
            case 'x':
            case 'X':    // hexadecimal format specifier
                i = va_arg(va_list, int);
                str = hex_to_str(i, &str_len);
                cmd = realloc(cmd, sizeof(char)*(cmd_len+str_len+1));
                strncpy(cmd + cmd_len, str, str_len);
                cmd_len += str_len;
                break;
            case 'n':    // nothing format specifier
                break;
            case '%':    // print % format specifier
                strncpy(cmd + cmd_len, "%", 1);
                cmd_len++;
                cmd = realloc(cmd, sizeof(char)*(cmd_len+1));
                break;
        }
    }
    // end cmd string literal
    *(cmd + cmd_len) = '\0';

    return exec_cmd_helper(cmd);
}