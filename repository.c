#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "repository.h"

int init_repo(const char *path)
{
 /*
  * Create the main .minigit directory.
  * This acts as the root folder for storing
  * repository metadata and objects.
  */
 if(mkdir(".minigit") != 0)
 {
  perror("Error creating .minigit");
  return -1;
 }

  /*
   * Create the objects directory.
   * This folder will store hashed file objects,
   * similar to Git's object storage.
   */ 
 if(mkdir(".minigit/objects") != 0)
 {
  perror("Error creating objects directory");
  return -1;
 }

/*
 * Create the refs directory.
 * This will later store branch references
 * and commit pointers.
 */
if(mkdir(".minigit/refs") != 0)
{
 perror("Error creating refs directory");
 return -1;
}

/*
 * Create the HEAD file.
 * HEAD stores information about the
 * currently active branch.
 */ 
FILE *head = fopen(".minigit/HEAD", "w");
if(head == NULL)
{
 perror("Error creating HEAD file");
 return -1;
}

/*
 * Set the default branch reference.
 * Similar to how Git points HEAD to
 * the master/main branch.
 */ 
fprintf(head, "ref: refs/heads/master\n");
 // Close the HEAD file after writing
fclose(head);

printf("Initialized empty Mini-Git repository in %s\n", path);
return 0;
}
