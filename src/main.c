#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "note_store.h"
#include "index.h"
#include "ui.h"

/* Build the full path for a notebook file: "data/notes/<name>.dat" */
static void build_filepath(const char *name, char *out, int size)
{
    snprintf(out, size, "%s%s.dat", NOTES_DIR, name);
}

static void notebook_menu(const char *filepath)
{
    int ch;
    do {
        ui_clear_screen();
        note_store_view(filepath);
        printf("1. Add note\n");
        printf("2. Update note\n");
        printf("3. Delete note\n");
        printf("4. Back to home\n");
        ch = ui_read_int("Select");

        switch (ch) {
            case 1: note_store_add(filepath);    break;
            case 2: note_store_update(filepath); break;
            case 3: note_store_delete(filepath); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }

        if (ch != 4) ui_pause();

    } while (ch != 4);
}

int main(void)
{
    char name[MAX_TITLE];
    char filepath[MAX_FILENAME];

    while (1) {
        ui_clear_screen();
        index_view();
        printf("\nType a notebook name to open/create, or 'q' to quit.\n");
        ui_read_line("> ", name, sizeof(name));

        if (strcmp(name, "q") == 0) {
            printf("Goodbye!\n");
            break;
        }

        if (strlen(name) == 0) continue;

        index_add(name);
        build_filepath(name, filepath, sizeof(filepath));
        notebook_menu(filepath);
    }

    return 0;
}
