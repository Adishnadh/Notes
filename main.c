#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "note.h"
#include "note_fun.h"

int main(){
    int ch;
    void add_note();
    void view_note();

    void update_note();
    void delete_note();

    while(1){
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
    }
    return 0;
    }

