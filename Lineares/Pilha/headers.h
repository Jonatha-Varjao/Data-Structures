#include <stdio.h>
#define MAX "n" // definir o limite da pilha

typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct pilha
{
	node *topo
	int tam;
}stack;

//criar pilha
void createStack(stack *p);

//pilha vazia
void isEmpty(stack *p);

//empilha
void stack(stack *p, int data);

//desempilha
void unstack(stack *p);

//imprime pilha
void printStack(stack *p);

//procura na pilha
void search(stack *p);

//destruir pilha
void deleteStack(stack *p);