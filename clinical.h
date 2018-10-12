/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   clinical.h
 * Author: David Serantes
 *
 * Created on 4 de octubre de 2018, 12:28
 */

#ifndef CLINICAL_H
#define CLINICAL_H

//All program functions in clinical.c
void print_list(Pacient * head);
void push(Pacient * head, int val);
void modify_history(Pacient * head);
void show_by_ID (Pacient * head);
void delete_pacient(Pacient * head);
void pacient_info(Pacient * current);

int store_ID(Pacient * head, int id);
int ask_ID(int ID);

Pacient* search_pacient(Pacient *current_node, int id);




#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* CLINICAL_H */

