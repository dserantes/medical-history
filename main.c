/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: David Serantes
 *
 * Created on 18 de septiembre de 2018, 15:09
 */

#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

/*
 * Clinical History
 */
void menu();
void strlcpy();
void push();
void print_list();
void modify_history();
void show_by_ID();
void delete_pacient();

int main(int argc, char** argv) {
    
    //Asign memory for the first pacient
    Pacient* head = NULL; 
    head = malloc(sizeof(Pacient));

    if(head == NULL)
    {
    return 1;
    }

    //Creating new pacients'`profile
    head->id=1;
    strlcpy(head->name, "David",100);
    strlcpy(head->surname, "Serantes",100);
    strlcpy(head->sex, "M",100);
    strlcpy(head->history, "Knee surgical intervention on 3/24/2018",100);
    head->age=21;
    
    head->next = malloc(sizeof(Pacient));
    head->next->id=2;
    strlcpy(head->next->name, "Mike",100);
    strlcpy(head->next->surname, "Jackson",100);
    strlcpy(head->next->sex, "M",100);
    strlcpy(head->next->history, "Throat surgical intervention on 3/29/2003",100);
    head->next->age=64;
    
    head->next->next = malloc(sizeof(Pacient));
    head->next->next->id=3;
    strlcpy(head->next->next->name, "Laura",100);
    strlcpy(head->next->next->surname, "Simpson",100);
    strlcpy(head->next->next->sex, "F",100);
    strlcpy(head->next->next->history, "Heart attack suffered on 6/3/2014",100);
    head->next->next->age=53;
    
    //Start
    menu();
    int op;
    scanf("%d",&op);
    
    //Menu options
    while(op>0){
        switch(op){
            case 1:
                show_by_ID(head);
                break;
            case 2:
                modify_history(head);
                break;
            case 3:
                push(head);
                break;
            case 4:
                delete_pacient(head);
                break;
            case 5:
                print_list(head);
                break;
        }
        if(op<1||op>6){
            printf("Type a valid choice (1,2,3,4,5 or 6)\n\n");
            printf("-----------------------------------------\n");
        }
        if(op==6){
           return (EXIT_SUCCESS); 
        }
        menu();
        scanf("%d",&op);
    };
    return (EXIT_SUCCESS);
 
}


//Menu style
void menu(){
    printf("-----------------------------------------");
    printf("\nVilnius Hospital Medical History 2018\n");
    printf("-----------------------------------------\n");
    printf("Choose any option\n");
    printf("-----------------------------------------\n");
    printf("1. Show pacient's profile\n");
    printf("2. Modify pacient's medical history\n");
    printf("3. Add new pacient\n");
    printf("4. Remove pacient\n");
    printf("5. List all pacients\n");
    printf("6. Quit\n");
    printf("-----------------------------------------\n");
}