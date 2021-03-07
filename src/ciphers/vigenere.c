#include "ciphers.h"

bool encrypt_vigenere(cipher_t *cipher){
    if(cipher->key_size < 1){
        return false;
    }
    else if (cipher->input_size != cipher->output_size){
        return false;
    }

    for(int i = 0; i < cipher->input_size; i++){
        for(int j = 0; j < cipher->key_size; j++){
            cipher->output[i] = cipher->input[i] + cipher->key[j];
        }
    }

    return true;
}

bool decrypt_vigenere(cipher_t *cipher){
    if(cipher->key_size < 1){
        return false;
    }
    else if (cipher->input_size != cipher->output_size){
        return false;
    }

    for(int i = 0; i < cipher->input_size; i++){
        for(int j = 0; j < cipher->key_size; j++){
            cipher->output[i] = cipher->input[i] - cipher->key[j];
        }
    }

    return true;
}