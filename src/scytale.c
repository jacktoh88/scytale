
#include <stdio.h>
#include <argp.h>

const static char doc[] = "scytale is a command line tool for having fun with ancient cryptography algorithms";
const static char args_doc[] = "";

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
            break;
        // Polybius cipher
        case 'p':
            break;
        // Vigenere cipher
        case 'v':
            break;
        // Path to key file
        case 'k':
            break;
        default:
            break;
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
}