#include <stdio.h>
#include "tree.h"
#include "hashing.h" // To call the Scanner
#include "blob.h"    // To call the Stockboy

int write_tree(char *tree_hash_out) {
    // 1. Send the Scanner to read the Receptionist's clipboard
    // We hash the ".minigit/index" file, and put the ID into the Boss's empty bucket.
    if (hash_file(".minigit/index", tree_hash_out) == -1) {
        printf("Error: Could not read the index. Did you 'add' any files yet?\n");
        return -1; // Thumbs down
    }

    // 2. Send the Stockboy to save a permanent backup in the warehouse
    // We give him the clipboard file, and the brand new Hash ID we just generated.
    if (create_blob(".minigit/index", tree_hash_out) == -1) {
        printf("Error: Could not save the Tree blueprint.\n");
        return -1; // Thumbs down
    }

    return 0; // Thumbs up!
}