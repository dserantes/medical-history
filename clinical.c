/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "structure.h"

//Looks for a pacient in a Linked List structure
Pacient* search_pacient(Pacient *current_node, int id){
    while ( current_node != NULL && current_node->next != NULL && current_node->id!=id){
   current_node = current_node->next;
  } 
    return current_node;
}

//Asks the user for an ID
int ask_ID(int id){
    //int id=0;
    
    while(id<1||id>500){
    getchar();   
    printf("-----------------------------------------\n");
    printf("Enter the pacient's ID (0--500)\n");
    printf("-----------------------------------------\n");
    scanf("%d",&id);
    }
    return id;
}

//Prints all pacient's information
void pacient_info(Pacient * current){
        printf("-----------------------------------------\n");
        printf("ID: %d\n", current->id);        
        printf("Name: %s\n", current->name);
        printf("Surname: %s\n", current->surname);
        printf("Sex: %s\n", current->sex);
        printf("Age: %d\n", current->age);
        printf("Medical History: %s\n", current->history);
        printf("-----------------------------------------\n\n");
}

//Lists all pacients
void print_list(Pacient * head) {
    Pacient * current = head;

    while (current != NULL) {
        pacient_info(current);
        current = current->next;
    }
}

//Function that modifies the medical history of a pacient
void modify_history(Pacient * head){
   char history[255];
    int id=0;
    
    id=ask_ID(id);
    
    Pacient *current_node = head;
    
    current_node=search_pacient(current_node, id);
    
    getchar();
    if(current_node->id==id){
    printf("-----------------------------------------\n");
    printf("Enter the pacient's last clinical history\n");
    printf("-----------------------------------------\n");
    gets(history);
    strcat(current_node->history,". ");
    strcat(current_node->history, history);
    printf("-----------------------------------------\n");
    printf("%s %s 's Clinical History has been modified\n",current_node->name, current_node->surname);
    }else{
        printf("-----------------------------------------\n");
        printf("Pacient not found\n");
    }
}

//Managing if the pacient is in the list
void show_by_ID (Pacient * head){
    
    int id=0;
    Pacient *current_node = head;
    
    id=ask_ID(id);
    
    current_node=search_pacient(current_node, id);
    
    if(current_node->id==id){
    pacient_info(current_node);
    }else{
        printf("-----------------------------------------\n");
        printf("Pacient not found\n");
        printf("-----------------------------------------\n");
    }
}

/**Check if ID is already used by another pacient. If ret==1
 * we will deny any new pacient with that ID
 * A new pacient cannot use an ID of a previous deleted profile.
*/int store_ID(Pacient * head, int id){
    
    int ids[255];
    int i=0;
    int j=0;
    int ret=0;
    Pacient *current_node = head;
    
 while ( current_node != NULL && current_node->next != NULL){
   ids[i]=current_node->id;  
   current_node = current_node->next;
   ids[i]=current_node->id;
   i++;
  }
    for(j=0;j<(int)( sizeof(ids) / sizeof(ids[0]) )+1;j++){
      if(id==ids[j]){
          ret=1;
      }  
    }
    return ret;   
}
    
//Adding a new pacient to the list
void push(Pacient * head){
    
        char name[25];
        char surname[25];
        int age;
        char sex[2];
        char history[255];
        int id;
  
        Pacient *current_node = head;
        Pacient *new_node;
 
  while ( current_node != NULL && current_node->next != NULL){
   current_node = current_node->next;
  }

  new_node = (Pacient *) malloc(sizeof(Pacient));
  
  id=ask_ID(id);
  
  while(store_ID(head,id)==1){
    printf("Enter a new pacient's id. %d is already used\n", id);
    scanf("%d",&id);
  }
  new_node->id = id;
  
  printf("Enter the pacient's name\n");
  scanf("%s",&name);
  strcpy(new_node->name, name);
  
  printf("Enter the pacient's surname\n");
  scanf("%s",&surname);
  strcpy(new_node->surname, surname);
  
  printf("Enter the pacient's age\n");
  scanf("%d",&age);
  
  while(age<0 || age>150){
        getchar();
        printf("Enter the pacient's age (0--150)\n");
        scanf("%d",&age);
  }
  new_node->age = age;
  
  printf("Enter the pacient's sex (M/F)\n");
  scanf("%s",&sex);
  
  while(*sex!='F' && *sex!='M' && *sex!='f' && *sex!='m'){
        getchar();
        printf("Enter the pacient's sex (M/F)\n");
        scanf("%s",&sex);
  }
  *sex=toupper(*sex);
  strcpy(new_node->sex,sex);
  
  getchar();
  
  printf("Enter the pacient's last medical history\n");
  gets(history);
  strcpy(new_node->history, history);
  
  printf("-----------------------------------------\n");
  printf("%s,%s has been added\n", surname, name);

  new_node->next= NULL;
  if (current_node != NULL)
    current_node->next = new_node;
  else
     head = new_node;
}
    
void delete_pacient(Pacient *head){ 
    int id=0;
    Pacient* todelete = head;
    
    id=ask_ID(id);
    
    todelete=search_pacient(todelete, id);
    
    if(todelete->id == id){
    // When node to be deleted is head node 
    if(head == todelete) { 
        if(head->next == NULL) { 
            printf("There is only one node. The list can't be made empty "); 
            return; 
        } 
  
        /* Copy the data of next node to head */
        head->id = head->next->id;
        head->age = head->next->age;
        strcpy(head->surname,head->next->surname);
        strcpy(head->surname,head->next->surname);
        strcpy(head->name,head->next->name);
        strcpy(head->sex,head->next->sex);
        strcpy(head->history,head->next->history);
        
        // store address of next node 
        todelete = head->next; 
  
        // Remove the link of next node 
        head->next = head->next->next; 
  
        // free memory 
        free(todelete); 
  
        return; 
    }
    printf("-----------------------------------------\n");
    printf("%s %s's profile has been deleted\n",todelete->name, todelete->surname);
    printf("-----------------------------------------\n");
    
    // When not first node, follow the normal deletion process 
  
    // find the previous node 
    Pacient *prev = head; 
    while(prev->next != NULL && prev->next != todelete) 
    prev = prev->next; 
  
    // Check if node really exists in Linked List 
    if(prev->next == NULL) { 
        printf("\n Given pacient is not present in the list"); 
        return; 
    }   
    // Remove node from Linked List 
    prev->next = prev->next->next; 
  
    // Free memory
    free(todelete);
    }else{
        printf("-----------------------------------------\n");
        printf("Pacient not found");
        printf("-----------------------------------------\n");
    }
    return;  
}