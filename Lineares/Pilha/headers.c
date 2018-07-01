#include "headers.h"

node *getNO(char *data)
{
	node *new = (node*)malloc(sizeof(node));
	strcpy((char*)&new->data, data);
	new->prox = NULL;
}


void createStack(stack *p)
{
	p->tam = -1;
	p->topo = NULL;
}


void printStack(stack *p)
{
	node *aux;
	aux = p->topo;
	while(aux != NULL)
	{
		printf("%c ", aux->data);
		aux = aux->prox;
	}
}


void push(stack *p)
{
	char data;
	scanf("\n %c",&data);
	node *new;
	new = getNO(&data);
	
	if(p->tam == -1)
	{		
		p->topo = new;
		p->tam++;
			;
	}else
	{
		new->prox = p->topo;
		p->topo = new;
		p->tam++;
	}
}

void pop(stack *p)
{
	node *aux;
	aux = p->topo;
	if(p->topo != NULL)
	{
		p->topo = p->topo->prox;
		printf("\nPOPED:[%c]\n",aux->data);
		free(aux);
	}else
		printf("EMPTY STACK\n");
}
void deleteStack(stack *p)
{
	node *aux = p->topo;
	if( p->topo != NULL )
	{
		node *temp;
		while(aux != NULL)
		{
			temp = aux;
			aux = aux->prox;
			p->topo = aux;
			printf("DELETING [%c]\n", temp->data);
			free(temp);
		}
	}else
		printf("EMPTY STACK\n");
}


void push2(char x)
{
	if (top == MAX-1)
		printf("OVERFLOW");
	else
	{
		stackString[++top] = x ;
	}
}

void pop2()
{
	printf("%c", stackString[top--]);
}
