#ifndef NOTE_LIST
#define NOTE_LIST

void add_to_index(const char *filename){
    FILE *index = fopen("files.ind", "a");
    char name[20];
    int flag=0;
    if (index == NULL) {
        printf("Error opening index file\n");
        return;
    }
    while (fgets(name, sizeof(name), index)) {
        if (strcmp(name, filename)==1)
            flag=1;
    }
    if (flag==1)
        fprintf(index, "%s\n", filename);

    fclose(index);
}
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
