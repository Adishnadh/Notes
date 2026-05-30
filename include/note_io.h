#ifndef NOTE_IO_H
#define NOTE_IO_H

#include <stdio.h>
#include "note.h"

/*
 * Write one Note to an open binary file.
 * Returns 1 on success, 0 on failure.
 */
int note_write(FILE *fp, const Note *note);

/*
 * Read one Note from an open binary file.
 * Returns a heap-allocated Note, or NULL at EOF / on error.
 * Caller must call note_free() when done.
 */
Note *note_read(FILE *fp);

#endif /* NOTE_IO_H */
