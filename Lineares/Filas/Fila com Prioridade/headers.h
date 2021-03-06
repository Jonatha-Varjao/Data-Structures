#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>

//estrutura com os dados
typedef struct node
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

void createQeue(fila *queue);

#endif // !HEADER_H