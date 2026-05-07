#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Note{
    char content[256];
    char timestamp[64];
};
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
    FILE *file = fopen("notes.dat","ab");//binary mode
    if (file == NULL){
        printf("error opening the file");
        return;
    }

    struct Note note;

    time_t now = time(NULL);
    strcpy(note.timestamp, ctime(&now));
    note.timestamp[strcspn(note.timestamp, "\n")] = '\0';

    printf("Enter your note: ");
    getchar();
    fgets(note.content, 256, stdin);

    fwrite(&note, sizeof(struct Note), 1, file);
    fclose(file);
    printf("Note saved!\n");
}  
void view_notes(){
    FILE *file = fopen("notes.dat","rb");//read binary
    if (file == NULL){
        printf("No notes found");
        return;
    }
    
    struct Note note;
    printf("\n---Your Notes---\n");
    while(fread(&note, sizeof(struct Note), 1, file)){
        printf("[%s] %s\n", note.timestamp, note.content);
    }
    fclose(file);
    printf("\n--------------------\n");
}

