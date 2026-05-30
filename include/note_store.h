#ifndef NOTE_STORE_H
#define NOTE_STORE_H

/*
 * High-level CRUD operations on a binary note file.
 * 'filepath' is the full relative path (e.g. "data/notes/work.dat").
 */

void note_store_add(const char *filepath);
void note_store_view(const char *filepath);
void note_store_update(const char *filepath);
void note_store_delete(const char *filepath);

#endif /* NOTE_STORE_H */
