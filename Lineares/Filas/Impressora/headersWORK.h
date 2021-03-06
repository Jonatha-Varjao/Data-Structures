#include <stdio.h>
#include <string.h>
#include <malloc.h>


/*
	FILA DE PRIORIDADE PARA IMPRESSÃO DE ARQUIVOS
	COM "CHEFIA" VALOR DE PRIORIDADE
*/
typedef struct Folha
{
	//ID DO ARQUIVO, E QTD DE COPIAS
	int id,copias;
	//PRIORIDADE SENDO "CHEFIA" o mais elevado
	char origem[32];
	struct Folha *prox;
}Folha;


typedef struct Fila
{
	// no maximo 10 pedidos na FILA***
	Folha *Primeiro;
	Folha *UltimoPrior;
	Folha *Ultimo;
	int qtd;

}Fila;

//GLOBAL PRIORITY SETENCE
char prioridade[32]={'c','h','e','f','i','a'};


Folha *getNO(int id, int copias,char *origem);

void pedidoDeimpressao(Fila *F);

void impressoraPronta(Fila *F); // remoção ou esperar

void mostraFila(Fila *F);

void criaFila(Fila* F);


//Folha* buscarFila(Fila F,int valor_id);//busca na fila (com o id) retornando qtd copias



void criaFila(Fila* F)
{
	F->Primeiro = F->Ultimo = NULL;
	F->UltimoPrior = NULL;
	F->qtd=0;
}

void mostraFila(Fila *F)
{
	Folha *aux = F->Primeiro;
	if((F->Primeiro == NULL))
	{
		printf("Impressoa Vazia\n");

	}else
		while(aux != NULL )
		{
			printf("\nid[%d] -->copias [%d] -->origem[%s]\n", aux->id, aux->copias, aux->origem);

			aux = aux->prox;
		}

}


void buscarFila(Fila *F, int valor_id)
{
	Folha *aux = F->Primeiro;
	if((F->Primeiro == NULL))
	{
		printf("Impressoa Vazia\n");

	}else
		while(aux != NULL)
		{
			if(aux->id == valor_id)
			{
				printf("\n numero de copias -> [%d]\n",aux->copias);
				return 0;
			}
			aux = aux->prox;
		}
		printf("\nId nao encontrado\n");
}

Folha *getNO(int id, int copias,char *origem)
{
	Folha *new = (Folha*)malloc(sizeof(Folha));
	new->id = id;
	new->copias = copias;
	strcpy((char*)&new->origem, origem);
	new->prox = NULL;
}


void pedidoDeimpressao(Fila *F)
{
	Folha *new,*aux,*auxFinal;
	
	//SETANDO O CONTEUDO DO NO
	int ID,copias;
	char origem[32];
	printf("File ID\n");
	scanf("%d",&ID);
	printf("Copy numbers:\n");
	scanf("%d",&copias);
	printf("File Origin\n");
	scanf("%s",&origem);


	//
	new = getNO(ID,copias,origem);
	if (!new) printf("alocação -> NULL\n");
	if(F->Primeiro == NULL)
	{
		F->Primeiro = F->Ultimo = new;
	}else if((strcmp(&new->origem,&prioridade) == 0) && strcmp(&F->Primeiro->origem,&prioridade) == 0 )
	{
		aux = F->Primeiro;
		while(aux != NULL && strcmp(&aux->origem,&prioridade) == 0 )
		{
			auxFinal = aux;
			F->UltimoPrior = aux;
			aux = aux->prox;
		}
		new->prox = auxFinal->prox;
		auxFinal->prox = new;
		F->UltimoPrior = new;
	}else if((strcmp(&new->origem,&prioridade) == 0) && strcmp(&F->Primeiro->origem,&prioridade) != 0)
	{
		aux = F->Primeiro;
		new->prox = aux;
		F->Primeiro = new;
	}else
	{	
		aux = F->Primeiro;
		while( aux->prox != NULL )
		{
			aux = aux->prox;
		}
		aux->prox = new;
		F->Ultimo = new;
	}
	
}

void impressoraPronta(Fila *F)
{

	if(F->Primeiro == NULL)
		printf("FILA VAZIA\n");
	else{
		Folha *aux;

		aux = F->Primeiro;
		F->Primeiro = F->Primeiro->prox;
		printf("\nDocumento Impresso: Id[%d], Qtd copias[%d], Origem:[%s] \n", aux->id, aux->copias, aux->origem);
		free(aux);
	}
}

void Destroy(Fila *F)
{
	
	Folha *aux,*deleted;
	aux = F->Primeiro;

	while(aux != NULL)
	{
		deleted = aux;
		aux = aux->prox;
		free(deleted);
	}
	F->Primeiro = F->Ultimo = F->UltimoPrior = NULL;

	free(aux);
	printf("Deleting List\n");
}