#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#define MAX 100 
#include <string.h>
int top, stackString[MAX];

typedef struct node
{
	char data;
	struct node *prox;
}node;

typedef struct pilha
{
	node *topo;
	int tam;
}stack;

//criar pilha
void createStack(stack *p);

//pilha vazia
void isEmpty(stack *p);

//empilha
void push(stack *p);

//desempilha
void pop(stack *p);

//imprime pilha
void printStack(stack *p);

//procura na pilha
void search(stack *p);

//destruir pilha
void deleteStack(stack *p);

#endif // !HEADERS_H