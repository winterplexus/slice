Slice Application
=================================
Slice is an application that will slice a file into smaller files based on the chunk size. Each smaller file sliced from the input file will have the original file name plus a period and part number as a suffix.

Application defaults include:

* input file path is used in place of output file path
* chunk size is 1024 bytes
* part number is 4 digits with leading zeros 
* part number sequence will begin at 1

The application is written in ANSI C for both Windows and Linux operating systems.

### slice

```
usage: slice (options)

options: -i <input file name>
         -o <output file path>
         -c <slice into n chunks [each chunk is 4096 bytes]
         -p <slice into n parts>
         -s show file names
         -? print this usage
```