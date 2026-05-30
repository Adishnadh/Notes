#ifndef INDEX_H
#define INDEX_H

/* Add 'name' to the index file if not already present. */
void index_add(const char *name);

/* Print all indexed notebook names to stdout. */
void index_view(void);

#endif /* INDEX_H */
