#include "headers.c"

int main()
{
	//TODO CODE HERE//
	fila Queue;
	int menu;
	do
	{
		printf("\n\n ***** MENU *****");
		printf("\n 1: Criar a Fila");	
		printf("\n 2: Printar a Fila");	
		printf("\n 3: Adicionar");
		printf("\n 4: Procurar");	
		printf("\n 5: Remover Primeiro");
		printf("\n 6: Remover Ultimo");
		printf("\n 7: Destruir a Fila");	
		printf("\n 8: Sair");
		printf("\n\n Entre a opcao: ");	
		scanf("%d", &menu);
		switch(menu)
		{
			case 1:
				system("clear");
				printf("Inicializando a Fila\n");
				createQeue(&Queue);
				break;
			case 2:
				system("clear");
				printQueue(&Queue);
				break;
			case 3:
				system("clear");
				queue(&Queue);
				break;
			case 4:
				system("clear");
				searchQueue(&Queue);
				break;
			case 5:
				system("clear");
				deQueue(&Queue);				
				break;
			case 6:
				system("clear");
				deQueueLast(&Queue);				
				break;
			case 7:
				system("clear");
				Destroy(&Queue);
				//TODO 
				break;
		}
	}while(menu != 8);
	printf("SAINDO..\n");
	return 0;
}

