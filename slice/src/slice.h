/*
**  @(#)slice.h
**
**  slice - slice file functions
**  ----------------------------
**
**  copyright (c) 2020-2022 Code Construct Systems (CCS)
*/
#ifndef __SLICE_H
#define __SLICE_H

#include <setjmp.h>

/*
** Default chunk size
*/
#ifndef _DEFAULT_CHUNK_SIZE
#define _DEFAULT_CHUNK_SIZE 4096
#else
#error  _DEFAULT_CHUNK_SIZE is defined in another include file
#endif


/*
** Default chunk count
*/
#ifndef _DEFAULT_CHUNK_COUNT
#define _DEFAULT_CHUNK_COUNT 1024
#else
#error  _DEFAULT_CHUNK_COUNT is defined in another include file
#endif

/*
** Base name part number format
*/
#ifndef _BASE_NAME_PART_NUMBER_FORMAT
#ifdef  _WINDOWS
#define _BASE_NAME_PART_NUMBER_FORMAT "%s\\%s.%04ld"
#else
#define _BASE_NAME_PART_NUMBER_FORMAT "%s/%s.%04ld"
#endif
#else
#error  _BASE_NAME_PART_NUMBER_FORMAT is defined in another include file
#endif

/*
** File name part number format
*/
#ifndef _FILE_NAME_PART_NUMBER_FORMAT
#define _FILE_NAME_PART_NUMBER_FORMAT "%s.%04ld"
#else
#error  _FILE_NAME_PART_NUMBER_FORMAT is defined in another include file
#endif

/*
** Unwind buffer stack pointer
*/
extern jmp_buf unwind_buffer_sp;

/*
** Define exit application macro (unwind stack to last setjmp)
*/
#ifndef EXIT_APPLICATION
#define EXIT_APPLICATION(_code) longjmp(unwind_buffer_sp, _code)
#else
#error  EXIT_APPLICATION is defined in another include file
#endif

#endif /* __SLICE_H */