#ifdef BLOB_H
#define BLOB_H

/*It's only job is to copy the file into .minigit folder and rename it to the hashID*/
int create_blob(const char *filename, const chat *hash);

#endif