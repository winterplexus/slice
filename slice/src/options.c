/*
**  @(#)options.c
**
**  slice - command line options
**  ----------------------------
**
**  copyright (c) 2020-2025 Code Construct Systems (CCS)
*/
#include "modules.h"

/*
** Local function prototypes
*/
static void GetOptionValues(int, char **, options_t *);
static void SetDefaultOptions(options_t *);
static void StoreStringOption(int, string_c_t[], int, string_c_t, size_t);
static void StoreChunksCount(int argc, string_c_t[], int, size_t *);
static void StorePartsCount(int argc, string_c_t[], int, size_t *);
static long ConvertStringToLong(string_c_t);
static void DisplayVersion(int);
static void DisplayUsage(void);

/*
** Get command line options
*/
void GetOptions(int argc, char **argv, options_t *opts) {
    /*
    ** Set default options
    */
    SetDefaultOptions(opts);

    /*
    ** Display usage if no argument; otherwise get option values
    */
    if (argc == 1) {
        DisplayUsage();
    }
    else {
        GetOptionValues(argc, argv, opts);
    }
}

/*
** Get option values
*/
static void GetOptionValues(int argc, char **argv, options_t *opts) {
    int i;

    /*
    ** Process each command line argument
    */
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-?") == 0) {
            DisplayUsage();
        }
        else if (strcmp(argv[i], "-i") == 0) {
            StoreStringOption(argc, argv, ++i, opts->input_file_name, sizeof(opts->input_file_name) - 1);
        }
        else if (strcmp(argv[i], "-o") == 0) {
            StoreStringOption(argc, argv, ++i, opts->output_file_path, sizeof(opts->output_file_path) - 1);
        }
        else if (strcmp(argv[i], "-c") == 0) {
            StoreChunksCount(argc, argv, ++i, &opts->chunks_count);
        }
        else if (strcmp(argv[i], "-p") == 0) {
            StorePartsCount(argc, argv, ++i, &opts->parts_count);
        }
        else if (strcmp(argv[i], "-s") == 0) {
            opts->show_file_names = TRUE;
        }
        else if (strcmp(argv[i], "-v") == 0) {
            DisplayVersion(argc);
        }
        else {
            EXIT_APPLICATION(EXIT_FAILURE);
        }
    }

    /*
    ** Set chunks count (if required)
    */
    if (opts->chunks_count < 1 && opts->parts_count < 1) {
        opts->chunks_count = _DEFAULT_CHUNK_SIZE;
        printf("information-> using default chunks count: %ld (units of %d bytes)\n", (long)opts->chunks_count, _DEFAULT_CHUNK_SIZE);
    }

    /*
    ** Set parts count to zero if chunks count is not zero
    */
    else if (opts->chunks_count && opts->parts_count) {
        opts->parts_count = 0L;
        printf("warning-> using chunks count over parts count: %ld\n", (long)opts->chunks_count);
    }
}

/*
** Set default options
*/
static void SetDefaultOptions(options_t *opts) {
    memset(opts->input_file_name, 0, _MAX_FILE_NAME_SIZE + 1);
    memset(opts->output_file_path, 0, _MAX_FILE_NAME_SIZE + 1);
    opts->chunks_count = 0L;
    opts->parts_count = 0L;
    opts->show_file_names = FALSE;
}

/*
** Store string option
*/
static void StoreStringOption(int argc, string_c_t argv[], int i, string_c_t argument, size_t size) {
    if (argc < i || !argv[i]) {
        DisplayUsage();
    }
    assert(argv[i]);
    strcpy_p(argument, size, argv[i], size);
}
/*
** Store chunks count
*/
static void StoreChunksCount(int argc, string_c_t argv[], int i, size_t *chunks_count) {
    if (argc < i || !argv[i]) {
        DisplayUsage();
    }
    assert(argv[i]);
    *chunks_count = (size_t)ConvertStringToLong(argv[i]);
}

/*
** Store parts count
*/
static void StorePartsCount(int argc, string_c_t argv[], int i, size_t *counts_count) {
    if (argc < i || !argv[i]) {
        DisplayUsage();
    }
    assert(argv[i]);
    *counts_count = (size_t)ConvertStringToLong(argv[i]);
}

/*
** Convert string to long integer
*/
static long ConvertStringToLong(string_c_t value) {
    char *end;

    long chunk_size = strtol(value, &end, 10);
    if (errno == ERANGE) {
        printf("error-> unable to convert string value to an integer value");
    }
    return (chunk_size);
}

/*
** Display version
*/
static void DisplayVersion(int argc) {
    printf("%s - slice text file utility\n", _VERSION_PRODUCT);
    printf("%s\n\n", _VERSION_RELEASE);

    /*
    ** Exit application (if no other command line arguments)
    */
    if (argc == 2) {
        EXIT_APPLICATION(EXIT_SUCCESS);
    }
}

/*
** Display usage
*/
static void DisplayUsage(void) {
    printf("usage: %s (options)\n\n", _VERSION_PRODUCT);
    printf("options: -i <input file name>\n");
    printf("         -o <output file path>\n");
    printf("         -c <slice into n chunks [each chunk is %d bytes]\n", _DEFAULT_CHUNK_SIZE);
    printf("         -p <slice into n parts>\n");
    printf("         -s show file names\n");
    printf("         -? print this usage\n");

    /*
    ** Exit application
    */
    EXIT_APPLICATION(EXIT_SUCCESS);
}
