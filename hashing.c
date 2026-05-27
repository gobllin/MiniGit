#include <stdio.h>
#include "hashing.h"

int hash_file(const char *filename, char *output_hash)
{
 // Open the file in read mode
 FILE *file = fopen(filename, "r");
 
 // Check if file opening failed
 if ( file == NULL)
 {
  perror("minigit: failed to open file");
  return -1;
 }
 // Variable to store final hash value
 unsigned long long hash_value = 0;

 // Variable to store each character read from file
 int ch;
 
 /*
  * Read file character by character until EOF
  * and keep adding ASCII values to hash_value
  */
 while ((ch = fgetc(file)) != EOF)
 {
  hash_value = hash_value + ch;
 }

 // Close the file after reading
 fclose(file);

  /*
   * Convert hash value into hexadecimal string format.
   * %040llx prints a 40-character hexadecimal number
   * padded with leading zeros.
   */
 snprintf(output_hash, 41, "%040llx", hash_value);
 
 return 0;
}
