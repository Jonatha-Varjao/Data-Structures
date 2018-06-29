#include "headers.c"


int main()//(int argc, char const *argv[])
{
	fila F;
	int menu;
	do
	{
		printf("\n\n ***** MENU *****");	
		printf("\n 1: Criar Fila");	
		printf("\n 2: Printar a Fila");	
		printf("\n 3: Adicionar um numero");
		printf("\n 4: Adicionar no inicio");
		printf("\n 5: Remover no final");
		printf("\n 6: Remover");	
		printf("\n 7: Procurar");	
		printf("\n 8: Destruir");
		printf("\n 9: SAIR");	
		printf("\n\n Entre a opcao: ");	
		scanf("%d", &menu);
		switch(menu)
		{
			case 1:
				system("clear");
				createQeue(&F);
				break;
			case 2:
				system("clear");
				printQueue(&F);
				break;
			case 3:
				system("clear");
				queue(&F);
				break;
			case 4:
				system("clear");
				queueFirst(&F);
				break;
			case 5:
				system("clear");
				deQueueLast(&F);
				break;
			case 6:
				system("clear");
				deQueue(&F);
				break;
			case 7:
				system("clear");
				searchQueue(&F);
				break;
			case 8:
				system("clear");
				Destroy(&F);
				break;
		}
	}while(menu != 9);

	printf("Saindo...\n");
	
	return 0;
}
