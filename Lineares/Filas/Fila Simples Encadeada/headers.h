#ifndef HEADERS_H
#include <stdio.h>
#include <malloc.h>

//estrutura com os dados
typedef struct node
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

#endif 