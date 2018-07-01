#include "headers.h"

void swap(node *p1,node *p2)
{
  int temp = p1->data;
  p1->data = p2->data;
  p2->data = temp;
}

void createLista(lista *l)
{
	l->head = l->tail = NULL;
	l->qtd=0;
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

void destroy(lista *l)
{
	node *aux,*auxfree;
	aux = l->head;
    while(aux!=l->tail)
    {
        auxfree = aux->next;
        free(aux);
		aux = auxfree;
    }
    l->head = l->tail = NULL;
	l->qtd = 0;
}

void insertHead(lista *l, int data)
{
	if(l->head==NULL)
	{
		node *new = (node*)malloc(sizeof(node));
		new = getNO(data);
		l->head = l->tail = new;
		l->qtd++;
	}else
	{
		node *new = (node*)malloc(sizeof(node));
		new = getNO(data);
		new->next = l->head;
		l->head->prev = new;
		l->head = new;
		l->qtd++;
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
		l->qtd--;
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
		l->qtd--;
		printf("\n[%d]removed\n",aux->data);
		free(aux);
	}
}

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
		printf("\nqtd:%d\n",l->qtd);
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
		printf("\nqtd:%d\n",l->qtd);
	}else printf("EMPTY LIST\n");
}