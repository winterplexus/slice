/*
**  @(#)options.h
**
**  slice - command line options
**  ----------------------------
**
**  copyright (c) 2020-2024 Code Construct Systems (CCS))
*/
#ifndef __OPTIONS_H
#define __OPTIONS_H

/*
** Command line options structure and type
*/
typedef struct options_s {
        char input_file_name[_MAX_FILE_NAME_SIZE + 1];
        char output_file_path[_MAX_FILE_NAME_SIZE + 1];
        size_t chunks_count;
        size_t parts_count;
        bool_c_t show_file_names;
} options_t;

/*
** Function prototypes
*/
extern void GetOptions(int, char **, options_t *);

#endif /* __OPTIONS_H */
