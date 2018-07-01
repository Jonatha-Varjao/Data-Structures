#ifndef HEADERS_H
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
//swap function
void swap(node *p1, node *p2);

//lista vazia
int emptyList(lista *l);

//iniciar a lsita
void createLista(lista *l);

//inserir no inicio
void insertHead(lista *l,int data);

//inserir no meio
void insertBody(lista *l, int data);

//inserir no final
void insertTail(lista *l, int data);

//imprimir a lista
void printLista(lista *l);

//remover inicio
void removeHead(lista *l);

//remover final
void removeTail(lista *l);

//imprimir (normal/inverso)
void printLista(lista *l);
void printListaReverse(lista *l);

//destruir
void destroy(lista *l);

#endif // !HEADERS_H