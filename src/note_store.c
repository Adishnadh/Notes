#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "note_store.h"
#include "note_io.h"
#include "note.h"
#include "config.h"
#include "ui.h"

/* ------------------------------------------------------------------ helpers */

static char *current_timestamp(void)
{
    time_t now = time(NULL);
    char  *ts  = malloc(MAX_TIMESTAMP);
    if (!ts) return NULL;
    strncpy(ts, ctime(&now), MAX_TIMESTAMP - 1);
    ts[strcspn(ts, "\n")] = '\0';
    return ts;
}

/* ------------------------------------------------------------------ CRUD */

void note_store_add(const char *filepath)
{
    FILE *fp = fopen(filepath, "ab");
    if (!fp) { perror("note_store_add: fopen"); return; }

    char content[MAX_CONTENT];
    ui_read_line("Enter your note", content, sizeof(content));

    char *ts   = current_timestamp();
    Note *note = note_create(content, ts ? ts : "unknown");
    free(ts);

    if (note) {
        note_write(fp, note);
        note_free(note);
        printf("Note saved!\n");
    }
    fclose(fp);
}

void note_store_view(const char *filepath)
{
    FILE *fp = fopen(filepath, "rb");
    if (!fp) { printf("No notes found.\n"); return; }

    printf("\n--- Your Notes ---\n");
    int   idx  = 1;
    Note *note;
    while ((note = note_read(fp)) != NULL) {
        printf("%d. [%s] %s\n", idx++, note->timestamp, note->content);
        note_free(note);
    }
    printf("------------------\n\n");
    fclose(fp);
}

void note_store_update(const char *filepath)
{
    FILE *fp = fopen(filepath, "rb");
    if (!fp) { printf("No notes found.\n"); return; }

    FILE *tmp = fopen(TEMP_FILE, "wb");
    if (!tmp) { perror("note_store_update: fopen temp"); fclose(fp); return; }

    int   target = ui_read_int("Enter note number to update");
    int   idx    = 1;
    Note *note;

    while ((note = note_read(fp)) != NULL) {
        if (idx == target) {
            char buf[MAX_CONTENT];
            ui_read_line("Enter new note", buf, sizeof(buf));

            char *ts = current_timestamp();
            note_free(note);
            note = note_create(buf, ts ? ts : "unknown");
            free(ts);
            printf("Note updated.\n");
        }
        if (note) { note_write(tmp, note); note_free(note); }
        idx++;
    }

    fclose(fp);
    fclose(tmp);
    remove(filepath);
    rename(TEMP_FILE, filepath);
}

void note_store_delete(const char *filepath)
{
    FILE *fp = fopen(filepath, "rb");
    if (!fp) { printf("No notes found.\n"); return; }

    FILE *tmp = fopen(TEMP_FILE, "wb");
    if (!tmp) { perror("note_store_delete: fopen temp"); fclose(fp); return; }

    int   target = ui_read_int("Enter note number to delete");
    int   idx    = 1;
    int   found  = 0;
    Note *note;

    while ((note = note_read(fp)) != NULL) {
        if (idx == target) {
            found = 1;
            note_free(note);
        } else {
            note_write(tmp, note);
            note_free(note);
        }
        idx++;
    }

    fclose(fp);
    fclose(tmp);
    remove(filepath);
    rename(TEMP_FILE, filepath);

    printf(found ? "Note deleted.\n" : "Invalid note number.\n");
}
