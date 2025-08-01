/*
**  @(#)version.h
**
**  slice - version information
**  ---------------------------
**
**  copyright (c) 2020-2025 Code Construct Systems (CCS)
*/
#ifndef __VERSION_H
#define __VERSION_H

/*
** Check if version product and string are defined in another include file
*/
#ifdef  _VERSION_PRODUCT
#error  _VERSION_PRODUCT is defined in another include file
#endif
#ifdef  _VERSION_RELEASE
#error  _VERSION_RELEASE is defined in another include file
#endif

/*
** Define product and version strings
*/
#define _VERSION_PRODUCT "slice"
#define _VERSION_RELEASE "slice 1.3.0 release 1"

#endif /* __VERSION_H */
