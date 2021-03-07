#include "ciphers.h"

// Encryption grid
// Row is stored in the first index
// Column is stored in the second index
uint8_t encryption_lookup[256][2];

// Decryption grid
// Stores the plaintext given the row and column
uint8_t decryption_lookup[16][16];

void setup_encryption_lookup(){
    for(int i = 0; i < sizeof(encryption_lookup); i++){
        encryption_lookup[i][0] = (i / 16);
        encryption_lookup[i][1] = i % 16;
    }
}

void setup_decryption_lookup(){
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            decryption_lookup[i][j] = (i*j) + j;
        }
    }
}

bool encrypt_polybius(cipher_t *cipher){
    return true;
}

bool decrypt_polybius(cipher_t *cipher){
    return true;
}