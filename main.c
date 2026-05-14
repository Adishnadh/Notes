#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "note.h"
#include "note_fun.h"
#include "note_list.h"

int main(/*int argc, char *argv[]*/){

    //int ch;
    void add_note(char fname[20]);
    void view_note(char fname[20]);
    void add_to_index(const char *filename);
    void view_index();
/*
    if(argc<2|| argc>2){
        printf("Usage : %s <filename>\n ", argv[0]);
        return 1;
    }*/
    char name[20];

    view_index();
    printf("Select file name from index or create a file: ");
    //getchar();
    fgets(name,sizeof(name),stdin);
   //strcpy(name,argv[1]);
   name[strcspn(name,"\n")]='\0';
   add_to_index(name);

   strcat(name,".dat");
    //void update_note();
    //void delete_note();

    /*while(1){
        printf("1.Add notes\n");
        printf("2.View notes\n");
        printf("3.Update notes\n");
        printf("4.Delete notes\n");
        printf("5.Exit\n");
        printf("select a choice: ");
        scanf("%d",&ch);

        switch(ch) {
            case 1 : add_note();
                break;
            case 2 : view_note();
                break;
             case 3 : update_note();
                break;
             case 4 : delete_note();
                break;

             case 5 :
                printf("---Good Bye!---\n");
                exit(0);
        }
    }*/
    while(1){
        printf("\033[H\033[J");
        view_note(name);
        
        add_note(name);
    }
    return 0;
    }

