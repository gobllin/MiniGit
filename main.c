#include <stdio.h>
#include <string.h>
#include "repository.h"
#include "hashing.h"

int main(int argc, char *argv[])
{
 /*
  * argc = number of command line arguments
  * argv = array storing all command line arguments
  *
  * Example:
  * ./minigit init
  *
  * argv[0] = ./minigit
  * argv[1] = init
  */

 if(argc < 2)
 {
  printf("Usage: minigit <command>\n");
  return 1;
 }

 /* 
 Checking if the second argument is "init" or not
 */
if (strcmp(argv[1], "init") == 0)
{
 if(init_repo(".") == 0)
 {
  printf("Initialized empty Mini-Git repository.\n");
 }
 else
 {
  printf("Failed to initialize repository.\n");
 }
}
/*
 * Compare the user command with "hash-object"
 *
 * Example:
 * ./minigit hash-object file.txt
 *
 * If argv[1] matches "hash-object",
 * generate a hash ID for the specified file.
 */
else if (strcmp(argv[1], "hashing-object") == 0)
{
 /*
  * Ensure the user provided a filename.
  *
  * argv[2] should contain the file path.
  */
 if( argc < 3)
 {
  printf("Error please provide a file to hash. \n");
  printf("Usage: minigit hash-object <filename>\n");
  return 1;
 }

 /*
 * Store the generated hash string.
 *
 * SHA-1 hashes are 40 characters long,
 * plus 1 character for the null terminator.
 */
 char bucket[41];// the empty bucket
 /*
  * Read the file specified by argv[2],
  * compute its hash, and store the result
  * inside the bucket array.
  */
 if(hash_file(argv[2], bucket) == 0)
 {
  /*
   * Print the generated hash ID.
   */
  printf("%s\n", bucket); //Print the HashID
 }
}
 /*
  * Handle commands that Mini-Git does not recognize.
  */
else
{
 printf("Unknown command: %s\n", argv[1]);
}

return 0;
}
