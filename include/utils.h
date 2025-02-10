#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

/* Existing utility function prototypes */
FILE *safeOpenFile(const char *filename, const char *mode);
int fileExists(const char *filename);
char *readFile(const char *filename);
int writeFile(const char *filename, const char *data);

/* New generic functions for reading and writing structures */

/**
 * writeStructToFile:
 * Writes any structure to a file in binary mode.
 * @param filename: The file name to write to.
 * @param data: Pointer to the structure data.
 * @param size: Size of the structure.
 * @return 0 on success, or EOF on error.
 */
int writeStructToFile(const char *filename, const void *data, size_t size);

/**
 * readStructFromFile:
 * Reads a structure from a file in binary mode.
 * @param filename: The file name to read from.
 * @param data: Pointer to the structure where data will be stored.
 * @param size: Size of the structure.
 * @return 0 on success, or EOF on error.
 */
int readStructFromFile(const char *filename, void *data, size_t size);

/* Convenience macros for easier usage */
#define WRITE_STRUCT(filename, s) writeStructToFile((filename), &(s), sizeof(s))
#define READ_STRUCT(filename, s) readStructFromFile((filename), &(s), sizeof(s))

#endif /* UTILS_H */
