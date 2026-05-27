#include <stdio.h>
#include "hashing.h"

int hash_file(const char *filename, char *output_hash)
{
 FILE *file = fopen(filename, "r");

 if ( file == NULL)
 {
  perror("minigit: failed to open file");
  return -1;
 }

 unsigned long long hash_value = 0;
 int ch;

 while ((ch = fgetc(file)) != EOF)
 {
  hash_value = hash_value + ch;
 }

 fclose(file);

 snprintf(output_hash, 41, "%040llx", hash_value);
 
 return 0;
}
