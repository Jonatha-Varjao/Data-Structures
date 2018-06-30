#include "headers.h"

node *getNO(int data)
{
	node *new = (node*)malloc(sizeof(node));
	if(new!=NULL)
	{
		new->data = data;
		new->prev = new->next = NULL;
	}else
		printf("ERRO NA ALOCACAO");
}

void createLista(lista *l)
{
	l->head = l->tail = NULL;
}

void emptyList(lista *l)
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
}

void insertList(lista *l, int data)
{
    node *new = getNO(data);
    // LISTA VAZIA
    if(l->head == NULL) 
        l->head = l->tail = new;
    else
    {
        new->prev = l->tail;
        new->next = l->head;
        l->head->prev = new;
        l->tail->next = new;
        l->tail = new;
    }
}

void printLista(lista *l)
{
    if(l->head == NULL)
        return;   
    node *aux = l->head;
    while(aux!=NULL)
    {
        printf("%d->", aux->data);
        aux = aux->next;
        if(aux == l->head)
            break;
    }
    printf("\n");
}

void printListaReverse(lista *l)
{
	printf("head: %d tail: %d\n", l->head->data, l->tail->data );
    node *aux = l->tail;
    while(aux!=NULL)
    {
        printf("%d<-", aux->data);
        aux = aux->prev;
        if(aux == l->head)
            break;
    }
    printf("%d\n", aux->data);
}

void removeList(lista *l)
{
    node *aux = l->tail;
    l->tail = aux->prev;
    l->tail->next = l->head;
    l->head->prev =  l->tail;
    free(aux);
}
//remover
