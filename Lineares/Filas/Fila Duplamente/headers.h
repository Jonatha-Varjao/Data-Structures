
#include <stdio.h>
#include <malloc.h>

//estrutura com os dados
typedef struct no
{
  int info;// ou um pointeiro void para valores heterogeneos
  struct node *prox;
  struct node *ant;
}node;

//ponteiros da fila (inicio,fim)
typedef struct queue
{
  node *primeiro;
  node *ultimo;
}fila;

// Funções da Fila e Funções Adicionais (DEQUE encadeado simples) // 

//criar fila
void createQeue(fila *queue);

//Get NO
node *getNO(int valor);

//inserir
void queue(fila *queue, int data);
//inserir inicio
void queueFirst(fila *queue,int data);

//remover
void deQueue(fila *queue);
//remover final
void deQueueLast(fila *queue);

//imprimir fila
void printQueue(fila *queue);

//busca na fila
void searchQueue(fila *queue, int data);



void createQeue(fila *queue){queue->primeiro = queue->ultimo = NULL;}


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

//SE QUISER BOTAR UMA VARIAVEL COUNT PRA ACHAR A POSIÇÃO NA FILA
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
				printf("[%d]FOUND IN POSITION [%d]\n", data, pos);
				break;
			}
			
			aux = aux->prox;
			pos++;
		}
		if (aux == NULL)
		{
			printf("[%d]NOT FOUND\n", data);
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
	if(queue == NULL){printf("FILA VAZIA\n");}
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

//Doubled Link Queue, just use ->ant, pretty simple
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
