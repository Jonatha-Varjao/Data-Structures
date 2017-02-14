
#include <stdio.h>
#include <malloc.h>

//estrutura com os dados
typedef struct no
{
  int info;// ou um pointeiro void para valores heterogeneos
  struct node *prox;
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
void queue(fila *queue);
//inserir inicio
void queueFirst(fila *queue);

//remover
void deQueue(fila *queue);
//remover final
void deQueueLast(fila *queue);

//imprimir fila
void printQueue(fila *queue);

//busca na fila
void searchQueue(fila *queue);




void createQeue(fila *queue){queue->primeiro = queue->ultimo = NULL;}


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

void queue(fila *queue)
{
	int data;
	printf("Number:\n");
	scanf("%d", &data);
	node *new = getNO(data);
	if(queue->primeiro == NULL)
	{
		queue->primeiro = queue->ultimo = new;
		
	}
	else
	{
		queue->ultimo->prox = new;
		queue->ultimo = new;
	}

}
void queueFirst(fila *queue)
{
	int data;
	printf("Number:\n");
	scanf("%d", &data);
	node *new = getNO(data);
	if(queue->primeiro == NULL)
	{
		queue->primeiro = queue->ultimo = new;
	}else
	{
		new->prox = queue->primeiro;
		queue->primeiro = new;
	}
}

void printQueue(fila *queue)
{

	if(queue->primeiro !=NULL)
	{
		printf("Printing the Queue:\n");
		node *aux = queue->primeiro;
		if(queue!= NULL)
		{
			while(aux != NULL)
			{
				printf("[%d]", aux->info );
				aux = aux->prox;
			}
			printf("\n");
		}
	}else
		printf("FILA VAZIA\n");
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
//como nossa estrutura só tem ->prox, fica um pouco trabalhoso remover no final

void deQueueLast(fila *queue)
{
	if((queue->primeiro == NULL) && (queue->ultimo == NULL)){printf("FILA VAZIA\n");}
	else
	{
		node *aux;
		node *auxFinal;
		aux = auxFinal = queue->primeiro;
		while(aux->prox != NULL)
		{
			auxFinal = aux;
			aux = aux->prox;
		}
		if(aux == queue->primeiro)
		{
			printf("Valor deletado do Final:[%d]\n",(aux)->info);
			queue->primeiro = queue->ultimo = NULL;
			free(aux);
		}else
		{		
			printf("Valor deletado do Final:[%d]\n",(aux)->info);
			auxFinal->prox = NULL;
			queue->ultimo = auxFinal;
			free(aux);
		}
	}
}

//SE QUISER BOTAR UMA VARIAVEL COUNT PRA ACHAR A POSIÇÃO NA FILA
void searchQueue(fila *queue)
{

	if (queue->primeiro == NULL){printf("FILA VAZIA\n");}
	else
	{
		int data;
		printf("Data to Search:\n");
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