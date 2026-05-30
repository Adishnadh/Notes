#ifndef NOTE_H
#define NOTE_H

typedef struct {
    char *content;
    char *timestamp;
} Note;

Note *note_create(const char *content, const char *timestamp);
void  note_free(Note *note);

#endif /* NOTE_H */
