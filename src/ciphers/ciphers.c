
#include "ciphers.h"
#include <string.h>

bool encrypt(cipher_t *cipher){
    if(!strcmp(cipher->name, "Caesar")){
        return encrypt_caesar(cipher);
    }
    else if(!strcmp(cipher->name, "Polybius")){
        cipher->output_size = cipher->input_size * 2;
        return encrypt_polybius(cipher);
    }
    else if(!strcmp(cipher->name, "Vigenere")){
        return encrypt_vigenere(cipher);
    }
    else {
        return false;
    }
}

bool decrypt(cipher_t *cipher){
    if(!strcmp(cipher->name, "Caesar")){
        return decrypt_caesar(cipher);
    }
    else if(!strcmp(cipher->name, "Polybius")){
        cipher->output_size = cipher->input_size / 2;
        return decrypt_polybius(cipher);
    }
    else if(!strcmp(cipher->name, "Vigenere")){
        return decrypt_vigenere(cipher);
    }
    else {
        return false;
    }
}