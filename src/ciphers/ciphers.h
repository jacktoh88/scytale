#ifndef CIPHERS_H
#define CIPHERS_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    char* name;
    uint8_t* key;
    size_t key_size;
    uint8_t* input;
    size_t input_size;
    uint8_t* output; 
    size_t output_size;
} cipher_t;

bool encrypt(cipher_t *cipher);
bool decrypt(cipher_t *cipher);

bool encrypt_casear(cipher_t *cipher);
bool encrypt_polybius(cipher_t *cipher);
bool encrypt_vigenere(cipher_t *cipher);

bool decrypt_caesar(cipher_t *cipher);
bool decrypt_polybius(cipher_t *cipher);
bool decrypt_vigenere(cipher_t *vigenere);

#endif