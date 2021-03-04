
#include "ciphers.h"
#include <string.h>

bool encrypt(cipher_t *cipher){
    if(!strcmp(cipher->name, "Caesar")){
        return encrypt_caesar(cipher);
    }
    else if(!strcmp(cipher->name, "Polybius")){
        return encrypt_polybius(cipher);
    }
    else if(!strcmp(cipher->name, "Vigenere")){

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
        return decrypt_polybius(cipher);
    }
    else if(!strcmp(cipher->name, "Vigenere")){

    }
    else {
        return false;
    }
}