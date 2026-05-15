#ifndef NOTE_LIST
#define NOTE_LIST

void add_to_index(const char *filename)
{
    FILE *index = fopen("files.ind", "a+");

    if (index == NULL) {
        printf("Error opening index file\n");
        return;
    }

    char name[256];
    char final_name[300];
    int exists = 0;

    // create final filename
    snprintf(final_name, sizeof(final_name), "%s.dat", filename);

    // move to beginning for reading
    rewind(index);

    // check if file already exists
    while (fgets(name, sizeof(name), index)) {

        // remove newline
        name[strcspn(name, "\n")] = '\0';

        if (strcmp(name, final_name) == 0) {
            exists = 1;
            break;
        }
    }

    // add only if not exists
    if (!exists) {
        fprintf(index, "%s\n", final_name);
        printf("Added to index: %s\n", final_name);
    }
    else {
        printf("File already indexed\n");
    }

    fclose(index);
}

/*void add_to_index(char *filename){
    FILE *index = fopen("files.ind", "a");
    char name[20];
    int flag=0;
    if (index == NULL) {
        printf("Error opening index file\n");
        return;
    }
    else if (fgetc(index)==EOF){
    while (fgets(name, sizeof(name), index)){
        printf("%s\n",name);
        if (strcmp(name, filename)==0){
            flag=1;
            printf("flag updated successfully");
        }
        else
            printf("not success");
    }
    strcat(filename,".dat");
    if (flag==1){
        fprintf(index, "%s\n", filename);

            printf("%s,/t%s",name,filename);
        printf("updated successfully\n");
    }
    else
        printf("Not successful");
    }

    else{
        fprintf(index, "%s\n", filename);
    }
    fclose(index);
}*/
void view_index() {
    FILE *index = fopen("files.ind", "r");
    char name[20];

    if (index == NULL) {
        printf("No files created yet\n");
        return;
    }

    while (fgets(name, sizeof(name), index)) {
        printf("%s", name);
    }

    fclose(index);
}

    
#endif
