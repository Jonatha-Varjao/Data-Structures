#include <stdio.h>

typedef struct node
{
	int data;
	struct node *next, *prev;
}node;

typedef struct lista
{
	node *head, *tail;
	int qtd;
}lista;

//lista vazia
void emptyList(lista l);

//iniciar a lsita
void createLista(lista *l);

//inserir no inicio
void insertHead(lista *l,int data);

//inserir no meio
void insertBody(lista *l, int data);

//inserir no final
void insertTail(lista *l, int data);

//inserir ordenado
void ordenedInsert(list *l, int data);

//ordenar lista
void sortList(lista *l);

//remover

//remover inicio

//remover meio

//remover final

//imprimir (normal/inverso)

//destruir