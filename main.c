#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "strings.h"
#include "base64.h"

int main(void) {

    printf("Common Functions Library.\n");

    char *string = "test1 test2 test3 test4 test5 test6";
    size_t num_tokens = 0;
    char *delimiter = " ";
    char **tokens = str_split(string, delimiter, &num_tokens);

    printf("num_tokens: %lu\n", num_tokens);
    for (int i=0; i<num_tokens; i++)
        printf("%s ", tokens[i]);
    printf("\n");

    string = "delimiter";
    delimiter = "delimiter";
    tokens = str_split(string, delimiter, &num_tokens);

    printf("num_tokens: %lu\n", num_tokens);
    for (int i=0; i<num_tokens; i++)
        printf("%s ", tokens[i]);
    printf("\n");

    string = "test1delimiter";
    delimiter = "delimiter";
    tokens = str_split(string, delimiter, &num_tokens);

    printf("num_tokens: %lu\n", num_tokens);
    for (int i=0; i<num_tokens; i++)
        printf("%s ", tokens[i]);
    printf("\n");

    string = "delimitertest1";
    delimiter = "delimiter";
    tokens = str_split(string, delimiter, &num_tokens);

    printf("num_tokens: %lu\n", num_tokens);
    for (int i=0; i<num_tokens; i++)
        printf("%s ", tokens[i]);
    printf("\n");

    char *data = "The above implementation is best with a language like JavaScript that handles string concatenation of arbitrary length strings very efficiently. Other languages (e.g. C) will work much more efficiently by allocating memory for a new string/array of the appropriate size (the output string length is easily calculated from the input string at the very beginning) and then simply setting each character index, as opposed to concatenation.";
    printf("data: %s\n", data);

    size_t base64_len = 0;
    char *base64 = malloc(256);
    base64encode(data, strlen(data), base64, 256);
    printf("base64: %s\n", base64);

    base64 = base64_encode(data, strlen(data), &base64_len);
    printf("base64 - 2: %s\n", base64);


    size_t decoded_data_len = 0;
    unsigned char * decoded_data = base64_decode(base64, base64_len, &decoded_data_len);
    printf("decoded data: %s\n", decoded_data);

    return 0;
}