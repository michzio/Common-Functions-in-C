//
// Created by Michal Ziobro on 22/09/2016.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char **str_split(const char *c_string, const char *delimiter, size_t *num_tokens) {

    char **tokens = NULL;       // array of tokens
    char *p = NULL, *t = NULL;  // pointer to C string, pointer to C token
    size_t token_len = 1;       // length of ith token
    int i = 0;                  // iterator of tokens

    // boundary conditions of C string and delimiter
    if( (c_string == NULL) || (delimiter == NULL) || (*delimiter == '\0') ) {
        fprintf(stderr, "%s: Could not split the given string with the given delimiter.\n", __func__);
        *num_tokens = 0;
        return NULL;
    }

    *num_tokens = 1;
    p = (char *) c_string;

    // calculate number of tokens
    while( *p != '\0' ) {
        if (strncmp(p, delimiter, strlen(delimiter)) == 0) {
            (*num_tokens)++;
            p += strlen(delimiter);
        } else {
            p++;
        }
    }

    // allocate array for tokens
    tokens = malloc( (*num_tokens) * sizeof(char *) );
    if(tokens == NULL)
        exit(1);

    // allocate space for each token in array of tokens
    p = (char *) c_string;
    while( *p != '\0' ) {
        if (strncmp(p, delimiter, strlen(delimiter)) == 0) {
            tokens[i] = malloc( sizeof(char) * token_len );
            if( tokens[i] == NULL )
                exit(1);
            i++;
            token_len = 0;
        }
        p++;
        token_len++;
    }
    tokens[i] = malloc( sizeof(char) * token_len );
    if(tokens[i] == NULL)
        exit(1);

    // copy tokens from C string into array of tokens
    i = 0;
    p = (char *) c_string;
    t = tokens[i];
    while( *p != '\0' ) {
        if (strncmp(p, delimiter, strlen(delimiter)) == 0) {
            *t = '\0';
            i++;
            t = tokens[i];
            p += strlen(delimiter);
        } else {
            *t = *p;
            t++;
            p++;
        }
    }
    *t = '\0'; i++;

    return tokens;
}