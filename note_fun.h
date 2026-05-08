#ifndef NOTE_FUN
#define NOTE_FUN

void add_note(){
    FILE *file = fopen("notes.dat","ab");//binary mode
    if (file == NULL){
        printf("error opening the file");
        return;
    }

    struct Note note;
    char buffer[1024];
    char time_buffer[64];
    int len;

    time_t now = time(NULL);
    strcpy(time_buffer, ctime(&now));
    time_buffer[strcspn(time_buffer, "\n")] = '\0';
    note.timestamp = malloc(strlen(time_buffer)+1);
    strcpy(note.timestamp, time_buffer);

    printf("Enter your note: ");
    getchar();
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")]='\0';
    note.content = malloc(strlen(buffer)+1);
    size_t hello = strlen(buffer);
    strcpy(note.content, buffer);
    /*
       saving files
    */

    len = strlen(note.content)+1;
    fwrite(&len, sizeof(int), 1,file);//length of Content
    fwrite(note.content, sizeof(char), len, file);// conent 

    len = strlen(note.timestamp)+1;
    fwrite(&len, sizeof(int), 1,file);//length of timestamp
    fwrite(note.timestamp, sizeof(char), len, file);// time stamp 


    fclose(file);
    free(note.content);
    free(note.timestamp);
    printf("\nNote saved!\n");
} 
void view_note(){
    FILE *file = fopen("notes.dat","rb");//read binary
    if (file == NULL){
        printf("No notes found\n");
        return;
    }

    int index = 1;
    int len;
    struct Note note;

    printf("\n---Your Notes---\n");

    while (fread(&len,sizeof(int),1,file)){
        note.content = malloc(len);
        fread(note.content, sizeof(char), len, file);

        fread(&len,sizeof(int),1,file);
        note.timestamp = malloc(len);
        fread(note.timestamp, sizeof(char),len, file);
   
 

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


    int content_len;
    int timestamp_len;

    int target;
    int index = 1;

    char buffer[1024];
    char time_buffer[64];

    view_note();

    printf("enter number the notes to be updated");
    scanf("%d",&target);
    
    while(fread(&content_len, sizeof(int), 1, file)){
        //allocating memory for content from file
        note.content = malloc(content_len);
         fread(note.content, sizeof(char), content_len, file);
         fread(&timestamp_len, sizeof(int), 1, file);

         //allocating memory for timestamp from file
         note.timestamp = malloc(timestamp_len);
        fread(note.timestamp, sizeof(char), timestamp_len, file);

         
        if(index == target){

            //allocate memory for new content from stdin
            printf("Enter new note: ");
            getchar();
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer,"\n")] = '\0';

            free(note.content);


            note.content = malloc(strlen(buffer)+1);
            strcpy(note.content, buffer);

            //allocating memory for timestamp from stdin
            time_t now = time(NULL);
            strcpy(time_buffer,ctime(&now));
            time_buffer[strcspn(time_buffer,"\n")]='\0';
            free(note.timestamp);

            note.timestamp = malloc(strlen(time_buffer)+1);
            strcpy(note.timestamp, time_buffer);
            printf("Note updated\n");



            printf("\n %s",note.content);
            printf("\n %s \n",note.timestamp);
        }

       
            content_len = strlen(note.content)+1;
            fwrite(&content_len, sizeof(int), 1,temp);//length of content
            fwrite(note.content, sizeof(char), content_len, temp);// content


            timestamp_len = strlen(note.timestamp)+1;
            fwrite(&timestamp_len, sizeof(int), 1, temp);
            fwrite(note.timestamp, sizeof(char), timestamp_len, temp);// time stamp written in the file
        
            index++;
            free(note.content);
            free(note.timestamp);
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
    int content_len;
    int timestamp_len;

    view_note();

    printf("\nEnter note number to delete: ");

    scanf("%d",&target);

    while(fread(&content_len,sizeof(int),1,file)){
        note.content=malloc(content_len);
        fread(note.content, sizeof(char),content_len, file);
        fread(&timestamp_len, sizeof(int) , 1, file);

        note.timestamp = malloc(timestamp_len);
        fread(note.timestamp,sizeof(char), timestamp_len,file);
        if(index != target){
            content_len = strlen(note.content)+1;
    fwrite(&content_len, sizeof(int), 1,temp);//length of string is written in file
    fwrite(note.content, sizeof(char), content_len, temp);// conent written in the file 

    timestamp_len= strlen(note.timestamp)+1;
    fwrite(&timestamp_len, sizeof(int), 1, temp);
    fwrite(note.timestamp, sizeof(char), timestamp_len, temp);// time stamp written in the file
    }
    free(note.content);
    free(note.timestamp);
        index++;        
    }

    fclose(file);
    fclose(temp);

    remove("notes.dat");

    rename("temp.dat","notes.dat");

    printf("Note deleted!\n");
} 
#endif

