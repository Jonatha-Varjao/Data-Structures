#include "headers.h"

void emptyQueue(lista *l)
{
	if(l->head == NULL)printf("EMPTY\n");
	else printf("NOT EMPTY\n");
}

node *getNo(int x)
{
	node *new;
	new = (node*)malloc(sizeof(node));
	if(new!=NULL)
	{
		new->data = x;
		new->next = NULL;
	}
}

void printList(lista *l)
{
	if(l->head == NULL) printf("EMPTY LIST\n");
	else
	{
		node *aux = l->head;
		while(aux!=NULL)
		{
			printf("[%d]->",aux->data);
			aux = aux->next;
		}
		//OrdenaLista(l);		
	}
}

int contaLista(lista *l)
{
	if(l->head == NULL)printf("EMPTY LIST\n");
	else
	{
		int cont=0;
		node *aux = l->head;
		while(aux!=NULL)
		{
			aux = aux->next;
			cont++;
		}
		return cont;
	}
}

void createList(lista *l)
{
	l->head == NULL;
}

void insertHead(lista *l,int data)
{
	node *new = (node*)malloc(sizeof(node));
	new = getNo(data);
	if(l->head == NULL)
	{
		l->head = new;
	}
	else
	{
		new->next = l->head;
		l->head = new;
	}
}

void insertTail(lista *l,int data)
{
	node *new = (node*)malloc(sizeof(node));
	new = getNo(data);
	if(l->head == NULL)
	{
		l->head = new;
	}else
	{
		node *aux;
		aux = l->head;
		while(aux->next != NULL)
			aux = aux->next;
		aux->next = new;
	}
}

void insertAny(lista *l, int data, int pos)
{
	if(l->head == NULL)printf("EMPTY LIST\n");
	else
	{
		int i,sizeList;		
		sizeList = contaLista(l);
		printf("\n%d\n", sizeList);
		if(sizeList <= pos)printf("NESSA POSICAO N ROLA PARÇA\n");	
		else
		{	
			
			if(pos == 0)
			{
				insertHead(l,data);
			}else if(pos == sizeList-1)
			{
				insertTail(l,data);
			}else
			{
				node *auxPast,*aux,*new = (node*)malloc(sizeof(node));
				aux = l->head;
				new = getNo(data);
				
				for(i=0; i < pos; i++)
				{
					auxPast = aux;
					aux = aux->next;
				}
				new->next = auxPast->next;
				auxPast->next = new;
			}
		}
	}
}

void removeHead(lista *l)
{
	if(l->head == NULL)printf("EMPTY LIST\n");
	else
	{
		node *aux = l->head;
		l->head = l->head->next;
		printf("REMOVED HEAD [%d]\n", aux->data);
		free(aux);
	}
}

void removeTail(lista *l)
{
	if(l->head == NULL)printf("EMPTY LIST\n");
	else
	{
		node *auxToStay,*aux = l->head;
		while(aux->next != NULL)
		{
			auxToStay = aux;
			aux = aux->next;
		}
		auxToStay->next = NULL;
		printf("REMOVED TAIL [%d]\n", aux->data);
		free(aux);
	}	
}

void removeAny(lista *l,int pos)
{
	if(l->head == NULL)printf("EMPTY LIST\n");
	else
	{
		int sizeList = contaLista(l);
		if(sizeList < pos)printf("NESSA POSICAO N PARÇA\n");
		else
		{
			if(pos == 0)
			{
				removeHead(l);
			}else if(pos == sizeList-1)
			{
				removeTail(l);
			}else
			{
				int i;
				node *auxToStay,*aux = l->head;
				for(i=0;i<pos;i++)
				{
					auxToStay = aux;
					aux = aux->next;
				}
				auxToStay->next = aux->next;
				printf("REMOVED [%d] IN POS [%d]\n",aux->data,pos);
				free(aux);
			}
		}
	}
}

void Search(lista *l,int data)
{
	node *aux = l->head;
	int pos = 0;
	while(aux!=NULL)
	{
		if(aux->data == data)
		{
			printf("FIND IN POS [%d]\n",pos);
			break;
		}
		pos++;
		aux = aux->next;
	}
	printf("[%d]NOT FOUND\n", data);
	return;
}

void Destroy(lista *l)
{
	node *auxRemoved,*aux = l->head;
	while(aux!=NULL)
	{
		auxRemoved = aux;
		aux = aux->next;
		l->head = aux;
		free(auxRemoved);
	}
}