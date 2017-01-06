
#include <stdio.h>

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

//inserir
void queue(fila *queue, int data);

//remover
void deQueue(fila *queue, int data);

//imprimir fila
void printQueue(fila *queue);

//busca na fila
void searchQueue(fila *queue, int data);

