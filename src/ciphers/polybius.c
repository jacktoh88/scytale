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

// Ignoring key for both encryption and decryption
// Instead using precalculated key look up tables
bool encrypt_polybius(cipher_t *cipher){
    // Output will by 2x input because each byte is transformed into 2
    if (cipher->input_size != cipher->output_size / 2){
        return false;
    }

    for(int i = 0; i < cipher->output_size; i+=2){
        cipher->output[i] = encryption_lookup[cipher->input[i/2]][0];
        cipher->output[i+1] = encryption_lookup[cipher->input[i/2]][1];
    }

    return true;
}

bool decrypt_polybius(cipher_t *cipher){
    // Output will by 1/2 input because evyer two bytes are reduced into 1
    if (cipher->input_size != cipher->output_size * 2){
        return false;
    }

    for(int i = 0; i < cipher->input_size; i+=2){
        uint8_t row = cipher->input[i];
        uint8_t column = cipher->input[i+1];
        cipher->output[i/2] = decryption_lookup[row][column];
    }

    return true;
}