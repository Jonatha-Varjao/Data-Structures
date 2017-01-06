#include <stdio.h>
#include <string.h>
#include <stdlib.h>



/*typedef struct conteudo
{
	int id,copias;
	char origem[32];

}conteudo
*/
typedef struct Folha
{
	int id,copias;
	char origem[32];
	struct Folha *prox;
	//conteudo conteudo;
}Folha;

typedef struct Fila
{
	// no maximo 10 pedidos na FILA***
	 Folha *Primeiro;
	 Folha *Ultimo;
	 int qtd;

}Fila;



void pedidoImpressao(Fila *F, int valor_id,int valor_copias, char *tipo_origem);

void impressoraPronta(Fila *F); // remoção ou esperar

void cancelaImpressao(Fila *F);//que porra ela quer com isso ? WTF

void mostraFila(Fila *F);

void criaFila(Fila* F);


//Folha* buscarFila(Fila F,int valor_id);//busca na fila (com o id) retornando qtd copias


void pedidoDeimpressao(Fila *F,int valor_id,int valor_copias,char *tipo_origem)
{
	Folha *novo_no,*aux,*aux2;
	char prioridade[32]={'c','h','e','f','i','a'};
	novo_no = (Folha*)malloc(sizeof(Folha));
	if (!novo_no) printf("alocação -> NULL\n");
	novo_no->prox = NULL;
	novo_no->id = valor_id;
	novo_no->copias = valor_copias;
	strcpy((char*)&novo_no->origem, tipo_origem);

	//SE FOR CHEFIA, JA BOTA COMO PRIMEIRO.

	if ((F->Primeiro == NULL) && (F->Ultimo == NULL))
	{
		F->Primeiro = F->Ultimo = novo_no;

	}else if(strcmp(novo_no->origem,prioridade)==0)
		{
			aux = F->Primeiro;

			while(aux != NULL)
			{

				if(aux->prox == NULL)
				{
					aux->prox = novo_no;
					printf("teste\n");
					return;
				}else
				{
					aux2 = aux;
					if(strcmp(aux2->origem,prioridade)==1)
					{
						novo_no->prox = aux2;
						aux->prox = novo_no;
						return;
					}
				}
				aux = aux->prox;
			}

	}else{
		F->Ultimo->prox = novo_no;
		F->Ultimo = novo_no;
	}
	F->qtd++;
}







	// 	Folha *aux = F->Primeiro;
	// 	while( aux!= NULL || strcmp(aux->origem,prioridade) == 0)
	// 		aux = aux->prox;



	// 	novo_no->prox = aux ;
	// 	aux->prox = novo_no;
	// 	// printf("NOVO PRIMEIRO\n");
	// 	//printf("id [%d]->copias[%d]->[%s]\n", novo_no->id,novo_no->copias,novo_no->origem);

	// }else
	// 	{
	// 		(F->Ultimo)->prox = novo_no;
	// 		F->Ultimo = novo_no;
	// 	}
	// F->qtd++;
	//printf("NOVO ULTIMO\n");
	//printf("id [%d]->copias[%d]->[%s]\n", novo_no->id,novo_no->copias,novo_no->origem);

//}


void buscarFila(Fila *F, int valor_id)
{
	Folha *aux = F->Primeiro;
	if((F->Primeiro == NULL) && (F->Ultimo == NULL))
	{
		printf("Impressoa Vazia\n");

	}else
		while(aux != NULL)
		{
			if(aux->id == valor_id)
			{
				printf("\nnumero de copias -> [%d]\n", aux->copias );
				return;//break; ñ tá funcionando 0.0 wtf
			}
			aux = aux->prox;
		}
		printf("\nId nao encontrado\n");
}

void criaFila(Fila* F)
{
	F->Primeiro = F->Ultimo = NULL;
	F->qtd=0;
}

void mostraFila(Fila *F)
{
	Folha *aux = F->Primeiro;
	if((F->Primeiro == NULL) && (F->Ultimo == NULL))
	{
		printf("Impressoa Vazia\n");

	}else
		while(aux != NULL )
		{
			printf("id[%d] --> copias [%d] -->origem[%s]\n", aux->id,aux->copias,aux->origem);

			aux = aux->prox;
		}

}
