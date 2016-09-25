//
// Created by Michal Ziobro on 24/09/2016.
//

#include <stdlib.h>
#include "base64.h"

static char character_table[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
                                 'Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f',
                                 'g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
                                 'w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'};

static unsigned char *inverse_character_table = 0;

static void inverse_character_table_init() {

    inverse_character_table = malloc(256);

    for(int i=0; i<64; i++)
        inverse_character_table[(unsigned char) character_table[i]] = i;
}
static void inverse_character_table_free() {
    free(inverse_character_table);
}

static int mod_table[] = {0, 2, 1};

char *base64_encode(const unsigned char *data, const size_t data_len, size_t *base64_len) {

    // calculate length of base64 string output
    *base64_len = 4*((data_len + 2)/3);

    // allocate base64 string
    char *base64 = malloc(*base64_len);
    if(base64 == 0) return 0;

    // encoding image data into base64 string
    int i=0, j=0;
    while(i < data_len) {

        // get three octets
        uint32_t octets[3];
        for(int n = 0; n < 3; n++)
            octets[n] = i < data_len ? (unsigned char)data[i++] : 0;

        // calculate its sum
        uint32_t triple = (octets[0] << 0x10) + (octets[1] << 0x08) + octets[2];

        // encode base64 using character table and indices calculated based on octets sum
        for(int n = 0; n < 4; n++)
            base64[j++] = character_table[(triple >> (3-n) * 6) & 0x3F];
    }

    for (int i = 0; i < mod_table[data_len % 3]; i++)
        base64[*base64_len - 1 - i] = '=';

    return base64;
}

unsigned char *base64_decode(const char *base64, const size_t base64_len, size_t *data_len) {

    if(inverse_character_table == 0) inverse_character_table_init();

    // base64 length must be multiplicity of 4
    if(base64_len % 4 != 0) return 0;

    // calculate decoded data length
    *data_len = base64_len / 4 * 3;
    if(base64[base64_len - 1] == '=') (*data_len)--;
    if(base64[base64_len - 2] == '=') (*data_len)--;

    // allocate space for decoded data
    unsigned char *data = malloc(*data_len);
    if(data == 0) return 0;

    // decoding base64 string into image data
    int i=0, j=0;
    while(i < base64_len) {

        // get four sextets
        uint32_t sextets[4];
        for(int n = 0; n < 4; n++)
            sextets[n] = base64[i] == '=' ? 0 & i++ : inverse_character_table[(unsigned char) base64[i++]];

        // calculate its sum
        uint32_t triple = (sextets[0] << 3 * 6) + (sextets[1] << 2 * 6) + (sextets[2] << 1 * 6) + (sextets[3] << 0 * 6);

        for(int n = 0; n < 3; n++)
            if(j < *data_len) data[j++] = (triple >> (2-n) * 8) & 0xFF;
     }

    inverse_character_table_free();

    return data;
}

// Wikipedia - Wiki Source implemenation example
// alternative implementation of base64 encoder and decoder

int base64encode(const void* data_buf, size_t dataLength, char* result, size_t resultSize)
{
    const char base64chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    const uint8_t *data = (const uint8_t *)data_buf;
    size_t resultIndex = 0;
    size_t x;
    uint32_t n = 0;
    int padCount = dataLength % 3;
    uint8_t n0, n1, n2, n3;

    /* increment over the length of the string, three characters at a time */
    for (x = 0; x < dataLength; x += 3)
    {
        /* these three 8-bit (ASCII) characters become one 24-bit number */
        n = ((uint32_t)data[x]) << 16; //parenthesis needed, compiler depending on flags can do the shifting before conversion to uint32_t, resulting to 0

        if((x+1) < dataLength)
            n += ((uint32_t)data[x+1]) << 8;//parenthesis needed, compiler depending on flags can do the shifting before conversion to uint32_t, resulting to 0

        if((x+2) < dataLength)
            n += data[x+2];

        /* this 24-bit number gets separated into four 6-bit numbers */
        n0 = (uint8_t)(n >> 18) & 63;
        n1 = (uint8_t)(n >> 12) & 63;
        n2 = (uint8_t)(n >> 6) & 63;
        n3 = (uint8_t)n & 63;

        /*
         * if we have one byte available, then its encoding is spread
         * out over two characters
         */
        if(resultIndex >= resultSize) return 1;   /* indicate failure: buffer too small */
        result[resultIndex++] = base64chars[n0];
        if(resultIndex >= resultSize) return 1;   /* indicate failure: buffer too small */
        result[resultIndex++] = base64chars[n1];

        /*
         * if we have only two bytes available, then their encoding is
         * spread out over three chars
         */
        if((x+1) < dataLength)
        {
            if(resultIndex >= resultSize) return 1;   /* indicate failure: buffer too small */
            result[resultIndex++] = base64chars[n2];
        }

        /*
         * if we have all three bytes available, then their encoding is spread
         * out over four characters
         */
        if((x+2) < dataLength)
        {
            if(resultIndex >= resultSize) return 1;   /* indicate failure: buffer too small */
            result[resultIndex++] = base64chars[n3];
        }
    }

    /*
     * create and add padding that is required if we did not have a multiple of 3
     * number of characters available
     */
    if (padCount > 0)
    {
        for (; padCount < 3; padCount++)
        {
            if(resultIndex >= resultSize) return 1;   /* indicate failure: buffer too small */
            result[resultIndex++] = '=';
        }
    }
    if(resultIndex >= resultSize) return 1;   /* indicate failure: buffer too small */
    result[resultIndex] = 0;
    return 0;   /* indicate success */
}

#define WHITESPACE 64
#define EQUALS     65
#define INVALID    66

static const unsigned char d[] = {
        66,66,66,66,66,66,66,66,66,66,64,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
        66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,62,66,66,66,63,52,53,
        54,55,56,57,58,59,60,61,66,66,66,65,66,66,66, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,66,66,66,66,66,66,26,27,28,
        29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,66,66,
        66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
        66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
        66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
        66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
        66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
        66,66,66,66,66,66
};

int base64decode (char *in, size_t inLen, unsigned char *out, size_t *outLen) {
    char *end = in + inLen;
    char iter = 0;
    size_t buf = 0, len = 0;

    while (in < end) {
        unsigned char c = d[*in++];

        switch (c) {
            case WHITESPACE: continue;   /* skip whitespace */
            case INVALID:    return 1;   /* invalid input, return error */
            case EQUALS:                 /* pad character, end of data */
                in = end;
                continue;
            default:
                buf = buf << 6 | c;
                iter++; // increment the number of iteration
                /* If the buffer is full, split it into bytes */
                if (iter == 4) {
                    if ((len += 3) > *outLen) return 1; /* buffer overflow */
                    *(out++) = (buf >> 16) & 255;
                    *(out++) = (buf >> 8) & 255;
                    *(out++) = buf & 255;
                    buf = 0; iter = 0;

                }
        }
    }

    if (iter == 3) {
        if ((len += 2) > *outLen) return 1; /* buffer overflow */
        *(out++) = (buf >> 10) & 255;
        *(out++) = (buf >> 2) & 255;
    }
    else if (iter == 2) {
        if (++len > *outLen) return 1; /* buffer overflow */
        *(out++) = (buf >> 4) & 255;
    }

    *outLen = len; /* modify to reflect the actual output size */
    return 0;
}
