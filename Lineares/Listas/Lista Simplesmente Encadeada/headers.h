#include <stdio.h>

//estrutura contendo os dados
typedef struct node
{
	int data;
	struct list *next;
}node;

typedef struct lista
{
	node *head, *tail;
}lista;

//lista vazia
void emptyQueue(lista l);

//iniciar a lista
void createList(lista *l);

//get no (aloca e armazena o dado inserido)
node *getNo(int x);

//inserir no inicio
void insertHead(lista **l, int data);

//inserir no final
void inserTail(lista **l, int data);

//inserir no meio
void insertMiddle(lista **l, int data);

//inserir em qualquer posição
void insertAny(lista **l, int data, int pos);

//remover no inicio
void removeHead(lista **l);

//remover no final
void removeTail(lista **l);

//remover no meio
void removeMiddle(lista **l);

//remover qualquer posição
void removeAny(lista **l,int pos);
