#include <stdio.h>
#include <string.h>
#include "index.h"
#include "config.h"

void index_add(const char *name)
{
    FILE *fp = fopen(INDEX_FILE, "a+");
    if (!fp) { perror("index_add: fopen"); return; }

    rewind(fp);
    char line[MAX_FILENAME];
    int  exists = 0;

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, name) == 0) { exists = 1; break; }
    }

    if (!exists) {
        fprintf(fp, "%s\n", name);
        printf("Notebook '%s' created.\n", name);
    }

    fclose(fp);
}

void index_view(void)
{
    FILE *fp = fopen(INDEX_FILE, "r");
    if (!fp) { printf("No notebooks yet. Create one!\n"); return; }

    printf("=== Notebooks ===\n");
    char line[MAX_FILENAME];
    int  i = 1;
    while (fgets(line, sizeof(line), fp))
        printf("  %d. %s", i++, line);
    printf("=================\n");

    fclose(fp);
}
