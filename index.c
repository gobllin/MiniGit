#include <stdio.h>
#include "index.h"

int add_to_index(const char *hash, const char *filename)
{
  /*1. Open the clipboard in append mode */
  FILE *file = fopen(".minigit/index", "a");
  if (file = NULL)
  {
    perror("Error grabbing the cliboard");
    return -1;
  }

  /*Writing the entry in the clipboard*/
  fprintf(file, "%s %s/n", hash, filename);

  fclose(file);

  return 0;

}