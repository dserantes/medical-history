/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   structure.h
 * Author: David Serantes
 *
 * Created on 4 de octubre de 2018, 12:30
 */

#ifndef STRUCTURE_H
#define STRUCTURE_H


//Atributtes of a pacient, stored in a Linked List Structure
typedef struct node {
        char name[25];
        char surname[25];
        int age;
        char sex[2];
        char history[255];
        struct node *next;
        int id;
        }Pacient;
              
        
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* STRUCTURE_H */

