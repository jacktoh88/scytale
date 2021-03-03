#ifndef CIPHERS_H
#define CIPHERS_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    char* name;
    uint8_t* key;
    uint8_t* input;
    uint8_t* output; 
} cipher_t;

bool encrypt(cipher_t *cipher);
bool decrypt(cipher_t *cipher);

#endif