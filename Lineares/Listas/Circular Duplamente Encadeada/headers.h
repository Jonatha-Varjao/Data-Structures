#ifndef HEADERS_H
#define HEADERS_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next, *prev;
}node;

typedef struct lista
{
	node *head,*tail;
	int qtd;
}lista;

//iniciar a lsita
void createLista(lista *l);

//inicia o no
node *getNO(int data);

//lista vazia
void emptyList(lista *l);

//inserir na lista
void insertList(lista *l,int data);

// remove o ultimo
void removeList(lista *l);

//printar lista
void printLista(lista *l);

void printListaReverse(lista *l);

#endif // !HEADERS_H