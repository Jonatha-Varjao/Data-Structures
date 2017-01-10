
#include <stdio.h>
#include <malloc.h>

//estrutura com os dados
typedef struct no
{
  int info;//ou um void* para valores heterogeneos
  struct node *prox;
}node;

//ponteiros da fila (inicio,fim)
typedef struct queue
{
  node *primeiro;
  node *ultimo;
}fila;

// Funções da Fila// 

//criar fila
void createQeue(fila *queue);

//Get NO
node *getNO(int valor);

//inserir
void queue(fila *queue, int data);

//remover
void deQueue(fila *queue);

//imprimir fila
void printQueue(fila *queue);

//busca na fila
void searchQueue(fila *queue, int data);


void createQeue(fila *queue)
{
	queue->primeiro = queue->ultimo = NULL;
}

node *getNO(int valor)
{
	node *new = (node*)malloc(sizeof(node));
	if(new != NULL)
	{
		new->prox = NULL;
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
		//queue->primeiro->prox = queue->ultimo->prox = NULL;
	}
	else
	{
		queue->ultimo->prox = new;
		queue->ultimo = new;
	}

}

void printQueue(fila *queue)
{
	node *aux = queue->primeiro;
	if(queue!= NULL){
		while(aux != NULL)
		{
			printf("[%d] ", aux->info );
			aux = aux->prox;
		}
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
		printf("Removendo [%d] da Fila\n",aux->info);
		free(aux);
	}
}