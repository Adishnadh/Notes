#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_NOTE 256

int main(){
    int ch;
    void add_note();
    void view_notes();
    while(1){
        printf("1.Add notes\n");
        printf("2.View notes\n");
        printf("3.Exit\n");
        printf("select a choice: ");
        scanf("%d",&ch);

        switch(ch) {
            case 1 : add_note();
                break;
            case 2 : view_notes();
                break;
            case 3 :
                printf("---Good Bye!---\n");
                exit(0);
        }
    }
    return 0;
    }
void add_note(){
    FILE *file = fopen("notes.txt","a");
    if (file == NULL){
        printf("error opening the file");
        return;
    }

    char note[MAX_NOTE];
    time_t now;
    time(&now);

    printf("Enter your note\n");
    getchar();
    fgets(note, MAX_NOTE, stdin);

    fprintf(file, "\n[%s]%s",ctime(&now), note);
    fclose(file);

    printf("Note saved!\n");
}  
void view_notes(){
    FILE *file = fopen("notes.txt","r");
    if (file == NULL){
        printf("No notes found");
        return;
    }
    char ch;
    printf("\n---Your Notes---\n");
    while((ch=fgetc(file)) != EOF){
        putchar(ch);
    }
    fclose(file);
    printf("\n--------------------\n");
}

