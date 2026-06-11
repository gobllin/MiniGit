#include <stdio.h>
#include <string.h>
#include "repository.h"
#include "hashing.h"
#include "blob.h"
#include  "index.h"

int main(int argc, char *argv[])
{
 // Checking if the user input less than 2 arguments in CLI
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
//Checking if the command is "hash-object"
else if (strcmp(argv[1], "hash-object") == 0)
{
    // Safety check: Did they provide a file?
    if( argc < 3)
    {
        printf("Error: please provide a file to hash. \n");
        printf("Usage: minigit hash-object <filename>\n");
        return 1; // Trapdoor out if they made a mistake
    }
    char bucket[41];// the empty bucket

    // Pass the file they typed (argv[2]) to the scanner
    if(hash_file(argv[2], bucket) == 0)
    {
        printf("%s\n", bucket); //Print the HashID
        
        // 2. NEW: The Scanner finished, now call the Stockboy!
        if(create_blob(argv[2], bucket) == 0)
        {
            // We don't need to print anything here, reaching this point means backup is safe
        }
    }
} // <--- THIS IS THE MISSING BRACE! It closes the hash-object room.

// ==========================================
// Phase 4: The 'add' command
// ==========================================
else if (strcmp(argv[1], "add") == 0)
{
    if ( argc < 3)
    {
        printf("Error: please provide a file to add. \n");
        printf("Usage: minigit add <filename>. \n");
        return 1;
    }
    
    char bucket[41];

    // Step A: Send the Scanner to get the DNA ID
    if (hash_file(argv[2], bucket) == 0) 
    {
        // Step B: Send the Stockboy to save the backup
        if (create_blob(argv[2], bucket) == 0) 
        {
            // Step C: Send the Receptionist to write it on her clipboard!
            if (add_to_index(bucket, argv[2]) == 0) 
            {
                printf("Success: Added '%s' to the staging area.\n", argv[2]);
            }
        }
    }
}
// ==========================================

else
{
    printf("Unknown command: %s\n", argv[1]);
}

return 0;
}
