#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "note_io.h"

/*
 * On-disk layout for one note (all lengths include the NUL terminator):
 *
 *   [int: content_len][char * content_len][int: timestamp_len][char * timestamp_len]
 */

int note_write(FILE *fp, const Note *note)
{
    int len;

    len = (int)strlen(note->content) + 1;
    if (fwrite(&len, sizeof(int), 1, fp) != 1) return 0;
    if (fwrite(note->content, 1, len, fp) != (size_t)len) return 0;

    len = (int)strlen(note->timestamp) + 1;
    if (fwrite(&len, sizeof(int), 1, fp) != 1) return 0;
    if (fwrite(note->timestamp, 1, len, fp) != (size_t)len) return 0;

    return 1;
}

Note *note_read(FILE *fp)
{
    int  len;
    char *content   = NULL;
    char *timestamp = NULL;
    Note *note      = NULL;

    if (fread(&len, sizeof(int), 1, fp) != 1) return NULL;
    content = malloc(len);
    if (!content) goto fail;
    if (fread(content, 1, len, fp) != (size_t)len) goto fail;

    if (fread(&len, sizeof(int), 1, fp) != 1) goto fail;
    timestamp = malloc(len);
    if (!timestamp) goto fail;
    if (fread(timestamp, 1, len, fp) != (size_t)len) goto fail;

    note = note_create(content, timestamp);

fail:
    free(content);
    free(timestamp);
    return note;
}
