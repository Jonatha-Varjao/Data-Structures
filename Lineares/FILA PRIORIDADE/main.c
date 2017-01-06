#include "headers.h"

int main(int argc, char const *argv[]){

	Fila F;
	
	char origem[32],origem2[32],origem3[32];
	scanf("%s %s %s", &origem,&origem2,origem3);
	
	//printf("%s\n", origem);
	criaFila(&F);

	pedidoDeimpressao(&F,10,5, origem);
	pedidoDeimpressao(&F,15,3, origem2);
	pedidoDeimpressao(&F,5,5, origem3);
	mostraFila(&F);
	//buscarFila(&F,5);
	//buscarFila(&F,15);
	



	return 0;
}
