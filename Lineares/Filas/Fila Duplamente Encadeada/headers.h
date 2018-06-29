#ifndef HEADERS_H
#include <stdio.h>
#include <malloc.h>

//estrutura com os dados
typedef struct node
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

void createQeue(fila *queue);


#endif // !HEADERS_H