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

//ordenar lista
void sortList(lista *l);

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

void swap(node *p1,node *p2)
{
  int temp = p1->data;
  p1->data = p2->data;
  p2->data = temp;
}

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
	if(l->head==NULL)
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

void insertTail(lista *l, int data)
{
	if(l->head == NULL)
	{
		node *new = (node*)malloc(sizeof(node));
		new = getNO(data);
		l->head = l->tail = new;
	}else
	{
		node *new = (node*)malloc(sizeof(node));
		new = getNO(data);
		new->prev = l->tail;
		l->tail->next = new;
		l->tail = new;
	}
}

void removeHead(lista *l)
{
	if(l->head == NULL)
	{
		printf("LISTA VAZIA");
	}else
	{
		node *aux = l->head;
		l->head = aux->next;
		l->head->prev = NULL;
		printf("\n[%d]removed\n",aux->data);
		free(aux);
	}
}

void removeTail(lista *l)
{
	if(l->head == NULL)
	{
		printf("LISTA VAZIA");
	}else
	{
		node *aux = l->tail;
		l->tail = aux->prev;
		l->tail->next = NULL;
		printf("\n[%d]removed\n",aux->data);
		free(aux);
	}
}

void sortList(lista *l)

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