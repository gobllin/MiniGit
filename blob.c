#include <stdio.h>
#include <string.h>
#include "blob.h"

int create_blob(const char *filename, const char *hash)
{
 /*
 *Open the original file.
 *And read it ("r")
 **filename is the name of the original file
 **hash is the hashID 
 */
FILE *source_file = fopen(filename, "r");
if(source_file == NULL)
{
 perror("Error: Could not open the original file.\n");
 return -1;
}
/*
*creating the exact same address for the new file
*we need a string that looks like: ".minigit/objects/c6...."
*/
char destination_path[256];
snprintf(destination_path, sizeof(destination_path), ".minigit/objects/%s", hash); 
/* 
*Opening the new file(The Destination) to WRITE to it ('w')
*If the file doesn't exist, "w" tells the computer to create it
*/
FILE *dest_file = fopen(destination_path, "w");
if(dest_file == NULL)
{
 perror("Error: Could not create destination path for blob storage.\n");
 fclose(source_file);/*cleaning up before leaving*/
 return -1;
}
/*
*Close files and release resources(copying like a scanner)
*/
int ch;
// Read each character until the end of the file
while ((ch = fgetc(source_file)) != EOF)
{
 //Actual copying happening
 fputc(ch, dest_file);
}
/*
*Cleaning up
*/
fclose(source_file);
fclose(dest_file);

return 0;
}