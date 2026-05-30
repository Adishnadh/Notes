#ifndef UI_H
#define UI_H

/* Clear the terminal screen. */
void ui_clear_screen(void);

/* Print prompt, read and return an integer. Loops until valid. */
int  ui_read_int(const char *prompt);

/* Print prompt, read a line into buf (at most size-1 chars, NUL-terminated). */
void ui_read_line(const char *prompt, char *buf, int size);

/* Wait for the user to press Enter. */
void ui_pause(void);

#endif /* UI_H */
