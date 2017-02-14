
#include <stdio.h>
#include <malloc.h>

//estrutura com os dados
typedef struct no
{
  int info;// ou um pointeiro void para valores heterogeneos
  float prior;
  struct node *prox;
  struct node *ant;
}node;

//ponteiros da fila (inicio,fim)
typedef struct fila
{
  node *primeiro;
  node *ultimo;
}fila;

// Funções da Fila e Funções Adicionais (DEQUE encadeado simples) // 

//criar fila
void createQeue(fila *queue);

//Get NO
node *getNO(int valor, float prior);

//inserir
void queue(fila *queue);

//remover
void deQueue(fila *queue);

//remover final
void deQueueLast(fila *queue);

//imprimir fila
void printQueue(fila *queue);

//busca na fila
void searchQueue(fila *queue);

void createQeue(fila *queue){queue->primeiro = queue->ultimo = NULL;}

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

//IF THERE'S A DATA > 1, SHOW ALL THE DATA ==
void searchQueue(fila *queue)
{
	if (queue->primeiro == NULL){printf("FILA VAZIA\n");}
	else
	{
		int data;
		printf("Data to search: \n");
		scanf("%d", &data);
		
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

void queue(fila *queue)
{
	int data;
	float prior;
	printf("File Data:\n");
	scanf("%d", &data);
	printf("File Priority:\n");
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

//Doubled Link Queue, just use ->ant, pretty simple
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
			printf("Dequeue Last Pos [%d]\n",aux->info);
			free(aux);
		}
	}
}

//Destroy the Entire List
void Destroy(fila *Queue)
{
	if(Queue->primeiro != NULL)
	{
		printf("Destroying All Data\n");
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