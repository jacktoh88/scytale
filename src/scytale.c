
#include <stdio.h>
#include <argp.h>
#include <string.h>
#include "ciphers.h"

#define MAX_KEY_LEN 1024
#define MAX_INPUT_LEN 4096

const static char doc[] = "scytale is a command line tool for having fun with ancient cryptography algorithms";
const static char args_doc[] = "";

char input_filename[100] = {0};
char output_filename[100] = {0};
char key_filename[100] = {0};

cipher_t cipher;

const static struct argp_option options[] = { 
    { 
        .name = "caesar",
        .key = 'c',
        .flags = OPTION_ARG_OPTIONAL,
        .group = 0,
        .arg = NULL,
        .doc = "Compare lines instead of characters."
    },
    {
        .name = "polybius",
        .key = 'p',
        .flags = OPTION_ARG_OPTIONAL,
        .group = 0,
        .arg = NULL,
        .doc = ""

    },
    {
        .name = "vigenere",
        .key = 'v',
        .flags = OPTION_ARG_OPTIONAL,
        .group = 0,
        .arg = NULL,
        .doc = "Compare case insensitive instead of case sensitive."
    },
    {
        .name = "key",
        .key = 'k',
        .flags = 0,
        .group = 0,
        .arg = "key",
        .doc = "Path to file containing key"
    },
    { 0 } 
};

// Parses each argument
error_t parse_opt(int key, char *arg, struct argp_state *state) {
    switch (key) {
        // Caesar cipher
        case 'c':
            cipher.name = "Caesar";
            break;
        // Polybius cipher
        case 'p':
            cipher.name = "Polybius";
            break;
        // Vigenere cipher
        case 'v':
            cipher.name = "Vigenere";
            break;
        // Path to key file
        case 'k':
            strncpy(key_filename, arg, sizeof(key_filename));
            break;
        // Path to input file
        case 'i':
            strncpy(input_filename, arg, sizeof(input_filename));
            break;
        // Path to output file
        case 'o':
            strncpy(output_filename, arg, sizeof(output_filename));
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }   
    return 0;
}

struct argp args = {
    .options = options,
    .parser = parse_opt,
    .args_doc = args_doc,
    .doc = doc,
    .children = NULL,
    .help_filter = NULL,
    .argp_domain = NULL
};

int main(int argc, char* argv[]){
    argp_parse(&args, argc, argv, 0, 0, NULL);
    // Read files into cipher struct
    FILE* key_fp = fopen(key_filename, "r");
    if(!key_fp){
        printf("Key file not found\n");
        return 1;
    }

    uint8_t key_data[MAX_KEY_LEN];
    cipher.key_size = fread(key_data, 1, MAX_KEY_LEN, key_fp);
    if(cipher.key_size == 0){
        printf("Error reading from key file\n");
    }
    cipher.key = key_data;

    FILE* input_fp = fopen(input_filename, "r");
    if(!input_fp){
        printf("Input file not found\n");
        return 1;
    }

    uint8_t input_data[MAX_INPUT_LEN];
    cipher.input_size = fread(input_data, 1, MAX_INPUT_LEN, input_fp);
    if(cipher.input_size == 0){
        printf("Error reading from input file\n");
    }
    cipher.input = input_data;

    fclose(key_filename);

}