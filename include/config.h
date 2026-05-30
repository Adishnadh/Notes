#ifndef CONFIG_H
#define CONFIG_H

/*
 * Storage paths (relative to working directory)
 */
#define DATA_DIR      "data/"
#define NOTES_DIR     "data/notes/"
#define INDEX_FILE    "data/index.dat"
#define TEMP_FILE     "data/temp.dat"

/*
 * Buffer sizes
 */
#define MAX_TITLE     100
#define MAX_CONTENT   2048
#define MAX_FILENAME  256
#define MAX_TIMESTAMP 64

/*
 * Application limits
 */
#define MAX_NOTES     1000

#endif /* CONFIG_H */
