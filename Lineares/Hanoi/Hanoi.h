//
// Created by jonatha on 07/04/18.
//

#ifndef TORREHANOI_HANOI_H
#define TORREHANOI_HANOI_H

#include <malloc.h>
#include "Hanoi.c"


//criar pilha
void createStack(stack *p, int nome);

//pilha vazia
void isEmpty(stack *p);

//empilha
void push(stack *p, int data);

//desempilha
int pop(stack *p);

//imprime pilha
void printStack(stack *p);

//procura na pilha
void search(stack *p);

//destruir pilha
void deleteStack(stack *p);

//Torrer de Hanoi
void towerHanoi(int n, stack* Inicial, stack* Final, stack* Auxiliar);

//Preenchimento da primeira pilha
void preenchePilha(stack* A, int qtd_Discos);


#endif //TORREHANOI_HANOI_H
