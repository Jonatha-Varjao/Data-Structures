//
// Created by jonatha on 07/04/18.
//
#include "Hanoi.h"

typedef struct node
{
    int data;
    struct node *prox;
}node;

typedef struct pilha
{
    node *topo;
    int tam;
    int nome;
}stack;


node *getNO(int data)
{
    node *new = (node*)malloc(sizeof(node));
    if(new!=NULL)
	{
		new->data = data;
		new->prox = NULL;
	}
}


void createStack(stack *p, int nome)
{
    p->tam = -1;
    p->topo = NULL;
    //strcpy((char*)&p->nome, nome);
    p->nome = nome;
}


void printStack(stack *p)
{
    node *aux;
    aux = p->topo;
    int a = aux->data;
    printf("\n");
    while(aux != NULL)
    {
        printf("[%d]", aux->data);
        aux = aux->prox;
    }
}


void push(stack *p, int data)
{
    node *new;
    new = getNO(data);
    if(p->tam == -1)
    {
        p->topo = new;
        p->tam++;
    }else
    {
        new->prox = p->topo;
        p->topo = new;
        p->tam++;
    }
}

int pop(stack *p)
{
    node *aux;
    aux = p->topo;
    int a;
    if(p->topo != NULL)
    {
        p->topo = p->topo->prox;
        //printf("\nPOP:[%d] da TORRE:[%d]\n",aux->data, p->nome);
        a = aux->data;
        free(aux);
        return a;
    }else
        printf("PILHA VAZIA\n");
}

void deleteStack(stack *p)
{
    node *aux = p->topo;
    if( p->topo != NULL )
    {
        node *temp;
        while(aux != NULL)
        {
            temp = aux;
            aux = aux->prox;
            p->topo = aux;
            printf("DELETANDO [%d]\n da torre [%d]", temp->data, p->nome);
            free(temp);
        }
    }else
        printf("PILHA VAZIA\n");
}


void towerHanoi(int n, stack *Inicial, stack *Final, stack *Auxiliar) {
    // parada da recursao
    if(n == 1)
    {
        printf("\nMovendo disco 1 da Torre %d para a Torre %d", Inicial->nome, Final->nome);
        push(Final, pop(Inicial));
    }else
    {
        towerHanoi(n-1, Inicial, Auxiliar, Final);
        push(Final, pop(Inicial));
        printf("\nMovendo disco %d da Torre %d para a Torre %d", n, Inicial->nome, Final->nome);
        towerHanoi(n-1, Auxiliar, Final, Inicial);
    }
}

void preenchePilha(stack *A, int qtd_Discos) {
    int i;
    //printf("Preenchendo a primeira Pilha A\n");
    for(i=qtd_Discos; i>0;--i)
    {
        //printf("Pilha A -> %d\n", i);
        push(A, i);
    }
    
}

