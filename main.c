#include<stdio.h>


#define MAX_NOTE 256
int main(){
    void add_note();
    add_note();
    return 0;
    }
void add_note(){
    FILE *file = fopen("notes.txt","a");
    if (file == NULL){
        printf("error opening the file");
        return;
    }

    char note[MAX_NOTE];

    printf("Enter your note\n");
    getchar();
    fgets(note, MAX_NOTE, stdin);

    fprintf(file, "%s", note);
    fclose(file);

    printf("Note saved!\n");
}  

