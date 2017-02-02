#include <stdio.h>
#include<stdlib.h>


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

//inserir ordenado
void ordenedInsert(lista *l, int data);

//ordenar lista
void sortList(lista *l);

void printLista(lista *l);

void createLista(lista *l)
{
	l->head = l->tail = NULL;
}

int emptyList(lista *l)
{
	if(l->head == NULL)return 1;
	else return 0;
}

node *getNO(int data)
{
	node *new = (node*)malloc(sizeof(node));
	if(new!=NULL)
	{
		new->data = data;
		new->prev = new->next = NULL;
	}else
		printf("ALLOCATION ERROR");
}

void insertHead(lista *l, int data)
{
	if(l==NULL)
	{
		node *new = (node*)malloc(sizeof(node));
		new = getNO(data);
		l->head = l->tail = new;
	}else
	{
		node *new = (node*)malloc(sizeof(node));
		new = getNO(data);
		new->next = l->head;
		l->head->prev = new;
		l->head = new;
	}
}
void insertTail(lista *l, int data);


void printLista(lista *l)
{
	
	if(emptyList(l) == 0)
	{
		node *aux = l->head;
		while(aux!=NULL)
		{
			printf("%d->", aux->data);
			aux = aux->next;
		}
	}
	else printf("EMPTY LIST\n");
}

void printListaReverse(lista *l)
{
	if(emptyList(l)== 0)
	{
		node *aux = l->tail;
		while(aux!=NULL)
		{
			printf("<-%d ", aux->data);
			aux = aux->prev;
		}
	}else printf("EMPTY LIST\n");
}
//remover

//remover inicio

//remover meio

//remover final

//imprimir (normal/inverso)

//destruir