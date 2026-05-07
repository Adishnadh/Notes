#ifndef NOTE_FUN
#define NOTE_FUN

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
void view_note(){
    FILE *file = fopen("notes.dat","rb");//read binary
    if (file == NULL){
        printf("No notes found\n");
        return;
    }

    int index = 1;
    struct Note note;
    printf("\n---Your Notes---\n");
    while(fread(&note, sizeof(struct Note), 1, file)){
        printf("%d. [%s] %s\n", index, note.timestamp, note.content);
        index ++;
    }
    fclose(file);
    printf("\n--------------------\n");
}
void update_note(){
    FILE * file = fopen("notes.dat","rb");
    if(file == NULL){
        printf("no notes found");
        return;
    }
    FILE *temp = fopen("temp.dat","wb");
    
    struct Note note;

    int target;
    int index =1;

    view_note();

    printf("enter number the notes to be updated");
    scanf("%d",&target);
    
    while(fread(&note, sizeof(struct Note), 1, file)){
        
        if(index == target){
            printf("Enter new note: ");
            getchar();
            fgets(note.content,256,stdin);

            note.content[strcspn(note.content,"\n")] = '\0';

            time_t now = time(NULL);

            note.timestamp[strcspn(note.timestamp,"\n")] = '\0';

            printf("Note updated!\n");
            }
           

            fwrite(&note,sizeof(struct Note),1,temp);
        index++;
    }
    fclose(file);
    fclose(temp);

    remove("notes.dat");
    rename("temp.dat", "notes.dat");
}
void delete_note(){

    FILE *file = fopen("notes.dat","rb");

    if(file == NULL){
        printf("No notes found\n");
        return;
    }

    FILE *temp = fopen("temp.dat","wb");

    struct Note note;

    int target;
    int index = 1;

    view_note();

    printf("\nEnter note number to delete: ");

    scanf("%d",&target);

    while(fread(&note,sizeof(struct Note),1,file)){

        if(index != target){

            fwrite(&note,sizeof(struct Note),1,temp);
        }

        index++;
    }

    fclose(file);
    fclose(temp);

    remove("notes.dat");

    rename("temp.dat","notes.dat");

    printf("Note deleted!\n");
}
#endif

