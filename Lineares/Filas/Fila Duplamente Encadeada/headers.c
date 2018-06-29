#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "headers.h"

void createQeue(fila *queue)
{
    queue->primeiro = queue->ultimo = NULL;
}

node *getNO(int valor)
{
	node *new = (node*)malloc(sizeof(node));
	if(new != NULL)
	{
		new->prox = new->ant = NULL;
		new->info = valor;
	}
	return new;
}

void queue(fila *queue, int data)
{
	
	node *new = getNO(data);
	if(queue->primeiro == NULL)
	{
		queue->primeiro = queue->ultimo = new;
		
	}
	else
	{
		new->ant = queue->ultimo;
		queue->ultimo->prox = new;
		queue->ultimo = new;
	}

}

void searchQueue(fila *queue, int data)
{

	if (queue->primeiro == NULL){printf("FILA VAZIA\n");}
	else
	{
		int pos = 1;
		node *aux = queue->primeiro;
		while(aux != NULL)
		{
			
			if(aux->info == data)
			{
				printf("[%d] achado na posicao [%d]\n", data, pos);
				break;
			}
			
			aux = aux->prox;
			pos++;
		}
		if (aux == NULL)
		{
			printf("[%d] nao encontrado\n", data);
		}
	}
}

void queueFirst(fila *queue, int data)
{
	node *new = getNO(data);
	if(queue->primeiro == NULL)
	{
		queue->primeiro = queue->ultimo = new;
	}else
	{
		new->prox = queue->primeiro;
		queue->primeiro->ant = new;
		queue->primeiro = new;
	}
}

void printQueue(fila *queue)
{
	node *aux = queue->primeiro;
	if(queue->primeiro == NULL){printf("FILA VAZIA\n");}
	else
	{
		while(aux != NULL)
		{
			printf("[%d]", aux->info);
			aux = aux->prox;
		}
		printf("\n");
	}
}

void deQueue(fila *queue)
{
	if (queue->primeiro == NULL){printf("FILA VAZIA\n"); }
	else
	{
		node *aux;
		aux = queue->primeiro;
		queue->primeiro = queue->primeiro->prox;
		queue->primeiro->ant = NULL;
		printf("Removendo [%d] da Fila\n",aux->info);
		free(aux);
	}
}

void deQueueLast(fila *queue)
{
	if(queue->primeiro == NULL){printf("FILA VAZIA\n");}
	else
	{
		node *aux = queue->ultimo;
		queue->ultimo = queue->ultimo->ant;
		queue->ultimo->prox = NULL;
		printf("Deqeue Last [%d]\n",aux->info);
		free(aux);
	}
}

void Destroy(fila *queue)
{
	node *aux,*auxFinal;
	aux = queue->primeiro;
	while(aux != NULL)
	{
		auxFinal = aux;
		aux = aux->prox;
		queue->primeiro = aux;
		free(auxFinal);		
	}

}