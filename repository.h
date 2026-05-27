#ifndef REPOSITORY_H
#define REPOSITORY_H
#ifndef REPOSITORY_H
#define REPOSITORY_H

/*
 * REPOSITORY_H
 *
 * Header file for repository-related functions.
 *
 * This file contains function declarations
 * used for initializing and managing the
 * Mini-Git repository.
 *
 * Include guards prevent this header file
 * from being included multiple times during
 * compilation, avoiding redefinition errors.
 */

/*
 * init_repo()
 *
 * Initializes a new Mini-Git repository
 * in the given path by creating required
 * directories and metadata files.
 *
 * Parameters:
 *   path -> directory where repository
 *           should be initialized
 *
 * Returns:
 *   0  -> success
 *  -1  -> failure
 */
int init_repo(const char *path);

#endif

int init_repo(const char *path);

#endif
