#include <stdlib.h>
#include <string.h>
#include "note.h"

Note *note_create(const char *content, const char *timestamp)
{
    Note *n = malloc(sizeof(Note));
    if (!n) return NULL;

    n->content   = malloc(strlen(content) + 1);
    n->timestamp = malloc(strlen(timestamp) + 1);

    if (!n->content || !n->timestamp) {
        free(n->content);
        free(n->timestamp);
        free(n);
        return NULL;
    }

    strcpy(n->content,   content);
    strcpy(n->timestamp, timestamp);
    return n;
}

void note_free(Note *note)
{
    if (!note) return;
    free(note->content);
    free(note->timestamp);
    free(note);
}
