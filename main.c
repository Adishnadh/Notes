#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include "note.h"
#include "note_fun.h"
#include "note_list.h"

int main(/*int argc, char *argv[]*/){

    void add_note(char fname[20]);
    void view_note(char fname[20]);
    void add_to_index (const char *filename);
    void view_index();
/*
    if(argc<2|| argc>2){
        printf("Usage : %s <filename>\n ", argv[0]);
        return 1;
    }*/
    char name[20];
    //bool funadd=1;
    int ch=0;

    while(1){

    printf("\033[H\033[J");
    view_index();
    printf("enter e to exit\n");
    printf("Select file name from index or create a file: ");

    //getchar();
    fgets(name,sizeof(name),stdin);
    if(strcmp(name,"e\n")==0){
        printf("Good bye\n");
        exit(0);
    }
   //strcpy(name,argv[1]);
   name[strcspn(name,"\n")]='\0';
   add_to_index(name);
  strcat(name,".dat");
    //void update_note();
    //void delete_note();
    while(1){
//printf("\033[H\033[J");
        view_note(name);
        printf("1.Add notes\t");
        //printf("2.View notes\n");
        printf("2.Update notes\t");
        printf("3.Delete notes\t");
        printf("4.Home\n");
        printf("select a choice: ");
       if(scanf("%d",&ch) != 1){

        printf("Invalid input\n");

        while(getchar() != '\n');

        continue;
    }

    while(getchar() != '\n'); 
        switch(ch) {
            case 1 : add_note(name);
                break;
          /*  case 2 : view_note();
                break;*/
             case 2 : update_note(name);
                break;
            
             case 3 : delete_note(name);
                break;
             case 4 : printf("note closing\n");
                break;
             default : printf("invalid selection\n");
        }
        if(ch == 4)
            break;
            }
    
    
    /*while(1){
       // printf("\033[H\033[J");
        view_note(name);
        
        add_note(name);
    }*/

   }
    return 0;
}
