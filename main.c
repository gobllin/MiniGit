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

 //Checking if the second argument is "init" or not
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
//Checking if the command is "hash-object."
else if (strcmp(argv[1], "hashing-object") == 0)
{
 // Safety check: Did they provide a file?
 if( argc < 3)
 {
  printf("Error please provide a file to hash. \n");
  printf("Usage: minigit hash-object <filename>\n");
  return 1;
 }
 char bucket[41];// the empty bucket

 // Pass the file they typed (argv[2]) to the scanner and Generate hash for the given file
 if(hash_file(argv[2], bucket) == 0)
 {
  printf("%s\n", bucket); //Print the HashID
 }
}
// Handle invalid commands
else
{
 printf("Unknown command: %s\n", argv[1]);
}

return 0;
}
