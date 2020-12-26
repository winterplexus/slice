/*
**  @(#)options.c
**
**  slice - command line options
**  ----------------------------
**
**  copyright (c) 2020 Code Construct Systems (CCS)
*/
#include "modules.h"

/*
** Local function prototypes
*/
static void GetOptionValues(int, char **, options_t *);
static void SetDefaultOptions(options_t *);
static void StoreInputFileName(int, string_c_t[], int, string_c_t, size_t);
static void StoreOutputFileName(int, string_c_t[], int, string_c_t, size_t);
static void StoreChunkSize(int argc, string_c_t[], int, size_t *);
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
        if (strcmp(argv[i], "-i") == 0) {
            StoreInputFileName(argc, argv, ++i, opts->input_file_name, sizeof(opts->input_file_name) - 1);
        }
        else if (strcmp(argv[i], "-o") == 0) {
            StoreOutputFileName(argc, argv, ++i, opts->output_file_path, sizeof(opts->output_file_path) - 1);
        }
        else if (strcmp(argv[i], "-c") == 0) {
            StoreChunkSize(argc, argv, ++i, &opts->chunk_size);
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
    ** Set chunk size (if required)
    */
    if (opts->chunk_size < 1) {
        opts->chunk_size = _DEFAULT_CHUNK_SIZE;
        printf("using default chunk size: %ld (units of 1024 bytes)\n", (long)opts->chunk_size);
    }
}

/*
** Set default options
*/
static void SetDefaultOptions(options_t *opts) {
    memset(opts->input_file_name, 0, _MAX_FILE_NAME_SIZE + 1);
    memset(opts->output_file_path, 0, _MAX_FILE_NAME_SIZE + 1);
    opts->chunk_size = 0L;
    opts->show_file_names = FALSE;
}

/*
** Store input file name
*/
static void StoreInputFileName(int argc, string_c_t argv[], int i, string_c_t argument, size_t size) {
    if (argc < i || !argv[i]) {
        DisplayUsage();
    }
    assert(argv[i]);
    strcpy_p(argument, size, argv[i], size);
}

/*
** Store output file name
*/
static void StoreOutputFileName(int argc, string_c_t argv[], int i, string_c_t argument, size_t size) {
    if (argc < i || !argv[i]) {
        DisplayUsage();
    }
    assert(argv[i]);
    strcpy_p(argument, size, argv[i], size);
}

/*
** Store chunk size
*/
static void StoreChunkSize(int argc, string_c_t argv[], int i, size_t *chunk_size) {
    if (argc < i || !argv[i]) {
        DisplayUsage();
    }
    assert(argv[i]);
    *chunk_size = (size_t)ConvertStringToLong(argv[i]);
}

/*
** Convert string to long integer
*/
static long ConvertStringToLong(string_c_t value) {
    char *end;

    long chunk_size = strtol(value, &end, 10);
    if (errno == ERANGE) {
        printf("error-> chunk size value is out of range");
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
    printf("where (options) include:\n");
    printf("  -i  [input file name]\n");
    printf("  -o  [output file path](default is input file name)\n");
    printf("  -c  [chunk size (units of 1024 bytes)]\n");
    printf("  -s  show file names\n");
    printf("  -v  display version\n");

    /*
    ** Exit application
    */
    EXIT_APPLICATION(EXIT_SUCCESS);
}