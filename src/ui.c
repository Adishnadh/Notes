#include <stdio.h>
#include <string.h>
#include "ui.h"

void ui_clear_screen(void)
{
    printf("\033[H\033[J");
}

int ui_read_int(const char *prompt)
{
    int ch;
    printf("%s: ", prompt);
    while (scanf("%d", &ch) != 1) {
        printf("Invalid input. %s: ", prompt);
        while (getchar() != '\n');
    }
    while (getchar() != '\n'); /* consume trailing newline */
    return ch;
}

void ui_read_line(const char *prompt, char *buf, int size)
{
    printf("%s: ", prompt);
    if (fgets(buf, size, stdin))
        buf[strcspn(buf, "\n")] = '\0';
}

void ui_pause(void)
{
    printf("Press Enter to continue...");
    while (getchar() != '\n');
}
