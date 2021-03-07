
#include <ciphers.h>

bool encrypt_caesar(cipher_t *cipher){
    // The key for the caesar cipher is just one byte
    uint8_t key = *(cipher->key);
    if(cipher->key_size < 1){
        return false;
    }
    else if (cipher->input_size != cipher->output_size){
        return false;
    }

    for(int i = 0; i < cipher->input_size; i++){
        cipher->output[i] = cipher->input[i] + key;
    }

    return true;
}

bool decrypt_caesar(cipher_t *cipher){
    // The key for the caesar cipher is just one byte
    uint8_t key = *(cipher->key);
    if(cipher->key_size < 1){
        return false;
    }
    else if (cipher->input_size != cipher->output_size){
        return false;
    }

    for(int i = 0; i < cipher->input_size; i++){
        cipher->output[i] = cipher->input[i] - key;
    }

    return true;
}