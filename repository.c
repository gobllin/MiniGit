#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "repository.h"

int init_repo(const char *path)
{
 // Creating the main folder
 if(mkdir(".minigit") != 0)
 {
  perror("Error creating .minigit");
  return -1;
 }

 //Creating vaults for files 
 if(mkdir(".minigit/objects") != 0)
 {
  perror("Error creating objects directory");
  return -1;
 }

//Creating the bookmarks for the branches
if(mkdir(".minigit/refs") != 0)
{
 perror("Error creating refs directory");
 return -1;
}

//Creating the headfile 
FILE *head = fopen(".minigit/HEAD", "w");
if(head == NULL)
{
 perror("Error creating HEAD file");
 return -1;
}

//Setting the defulat branch to master 
fprintf(head, "ref: refs/heads/master\n");
fclose(head);

printf("Initialized empty Mini-Git repository in %s\n", path);
return 0;
}