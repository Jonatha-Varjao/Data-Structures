#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "headers.h"

void createQeue(fila *queue)
{
    queue->primeiro = queue->ultimo = NULL;
}

node *getNO(int info,float prior)
{
	node *new = (node*)malloc(sizeof(node));
	if(new != NULL)
	{
		new->prox = new->ant = NULL;
		new->info = info;
		new->prior = prior;
	}
	return new;
}

void printQueue(fila *queue)
{
	node *aux = queue->primeiro;
	if(aux == NULL){printf("FILA VAZIA\n");}
	else
	{
		while(aux != NULL)
		{
			printf("[%d](%f)->", aux->info, aux->prior);
			aux = aux->prox;
		}
		printf("\n");
	}
}

void searchQueue(fila *queue)
{
	if (queue->primeiro == NULL){printf("FILA VAZIA\n");}
	else
	{
		int data;
		printf("Pesquisa: \n");
		scanf("%d", &data);
		
		int pos = 1;
		node *aux = queue->primeiro;
		while(aux != NULL)
		{
			
			if(aux->info == data)
			{
				printf("[%d]ACHADO NA POSICAO [%d]\n", data, pos);
				break;
			}
			
			aux = aux->prox;
			pos++;
		}
		if (aux == NULL)
		{
			printf("[%d]NAO ENCONTRADO\n", data);
		}
	}
}

void queue(fila *queue)
{
	int data;
	float prior;
	printf("Dado:\n");
	scanf("%d", &data);
	printf("Prioridade:\n");
	scanf("%f", &prior);

	node *new = getNO(data,prior);
	if(queue->primeiro == NULL)
	{
		queue->primeiro = queue->ultimo = new;
	}
	else if( new->prior > queue->primeiro->prior )
	{
		queue->primeiro->ant = new;
		new->prox 			 = queue->primeiro;
		queue->primeiro 	 = new;
	}else
	{	
		new->ant 			= queue->ultimo;
		queue->ultimo->prox = new;
		queue->ultimo 		= new;
	}	
}

void deQueue(fila *queue)
{
	if ((queue->primeiro == NULL)&& (queue->ultimo == NULL)){printf("FILA VAZIA\n"); }
	else if(queue->primeiro->prox == NULL)
	{
		node *aux;
		aux = queue->primeiro;
		queue->primeiro = queue->ultimo = NULL;
		printf("Dequeue [%d] \n",aux->info);
		free(aux);
	}else 
	{
		node *aux;
		aux = queue->primeiro;
		queue->primeiro = queue->primeiro->prox;
		queue->primeiro->ant = NULL;
		printf("Dequeue [%d] \n",aux->info);
		free(aux);
	}
}

void deQueueLast(fila *queue)
{
	if((queue->primeiro == NULL)&& (queue->ultimo == NULL)){printf("FILA VAZIA\n");}
	else
	{
		node *aux = queue->ultimo;
		if(aux == queue->primeiro)
		{
			printf("Dequeue [%d] \n",aux->info);
			queue->primeiro = queue->ultimo = NULL;
			free(aux);
		}else
		{
			queue->ultimo = queue->ultimo->ant;
			queue->ultimo->prox = NULL;
			printf("Dequeue Ultima Posicao [%d]\n",aux->info);
			free(aux);
		}
	}
}

void Destroy(fila *Queue)
{
	if(Queue->primeiro != NULL)
	{
		printf("Destruindo todas os dados\n");
		node *aux,*auxfree;
		
		aux = Queue->primeiro;
		while(aux != NULL)
		{
			auxfree = aux;
			aux 	= aux->prox;
			free(auxfree);
		}
		Queue->primeiro = Queue->ultimo = NULL;
		
		printQueue(Queue);
	}else
		printf("FILA VAZIA\n");
}