#include <stdio.h>
#include <string.h>
#include "repository.h"
#include "hashing.h"
#include "blob.h"
#include "index.h"
#include "tree.h"

int main(int argc, char *argv[])
{
    /* Check if the user typed enough words.
     If they just type "./minigit" and hit enter, argc is 1.
     We need at least 2 words (e.g., "./minigit init").
    */
    if(argc < 2)
    {
        printf("Usage: minigit <command>\n");
        return 1;
    }

    /*
     
     Checks if the second word typed was "init".
     If so, we build the hidden .minigit folder structure.
    */
    if (strcmp(argv[1], "init") == 0)
    {
        /*
         Call the init_repo function from repository.c.
         "." means "create it right here in the current folder".
        */
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
     Checks if the second word typed was "hash-object".
     This calculates the DNA of a file and backs it up.
    */
    else if (strcmp(argv[1], "hash-object") == 0)
    {
        /*
         Safety check: Did they provide a file?
         We need 3 words: "./minigit hash-object test.txt".
        */
        if( argc < 3)
        {
            printf("Error: please provide a file to hash. \n");
            printf("Usage: minigit hash-object <filename>\n");
            return 1; 
        }
        
        /* The Empty Bucket. 
         40 slots for the ID, 1 slot for the \0 stop sign. 
        */
        char bucket[41];

        /*
         Call the Scanner (hashing.c) to read the file.
         The Scanner writes the 40-character ID into 'bucket'.
        */
        if(hash_file(argv[2], bucket) == 0)
        {
            /* Print the generated ID to the terminal */
            printf("%s\n", bucket); 
            
            /*
             Call the Stockboy (blob.c) to save the backup.
             We hand him the original file and the new ID.
            */
            if(create_blob(argv[2], bucket) == 0)
            {
                /* Backup successful. No need to print anything here. */
            }
        }
    }
    
    /*
     Checks if the second word typed was "add".
     This triggers the Staging Area pipeline (Scanner -> Stockboy -> Receptionist).
    */
    else if (strcmp(argv[1], "add") == 0)
    {
        /*
         Safety check: Ensure a file name was provided.
        */
        if ( argc < 3)
        {
            printf("Error: please provide a file to add. \n");
            printf("Usage: minigit add <filename>. \n");
            return 1;
        }
        
        /* Create the empty bucket for the Hash ID */
        char bucket[41];

        /*
         Step A: Send the Scanner to calculate the DNA of the file.
        */
        if (hash_file(argv[2], bucket) == 0) 
        {
            /*
             Step B: Send the Stockboy to copy the file into the warehouse.
            */
            if (create_blob(argv[2], bucket) == 0) 
            {
                /*
                 Step C: Send the Receptionist to write it down.
                 She appends the Hash ID and File Name to '.minigit/index'.
                */
                if (add_to_index(bucket, argv[2]) == 0) 
                {
                    printf("Success: Added '%s' to the staging area.\n", argv[2]);
                }
            }
        }
    }
    
    /*
     Checks if the second word typed was "write-tree".
     This freezes the current Staging Area into a permanent Map.
    */
    else if (strcmp(argv[1], "write-tree") == 0)
    {
        /* The empty bucket for the brand new Map ID.
        */
        char tree_bucket[41]; 

        /*
         Call the Middle Manager (tree.c).
         He will command the Scanner and Stockboy to process the index file.
        */
        if (write_tree(tree_bucket) == 0)
        {
            /*
             If successful, the bucket is now full. 
             Print the final Map ID to the screen.
            */
            printf("Success! Tree created with ID: %s\n", tree_bucket);
        }
    }
    
    /*
     If the user typed a command that doesn't exist 
     (like "./minigit dance"), we catch it here.
    */
    else
    {
        printf("Unknown command: %s\n", argv[1]);
    }

    return 0;
}
