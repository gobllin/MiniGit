#ifndef HASHING_H
#define HASHING_H
/*
 * HASHING_H
 *
 * Header file for hashing-related functions.
 *
 * This file contains function declarations
 * that can be used in other source files.
 *
 * #ifndef, #define, and #endif are called
 * include guards. They prevent the header
 * file from being included multiple times,
 * which avoids redefinition errors.
 */


/*
 * hash_file()
 *
 * Generates a hash string for the given file.
 *
 * Parameters:
 *   filename     -> name/path of the file
 *   output_hash  -> array where generated hash will be stored
 *
 * Returns:
 *   0  -> success
 *  -1  -> failure
 */
int hash_file(const char *filename, char *output_hash);

#endif
