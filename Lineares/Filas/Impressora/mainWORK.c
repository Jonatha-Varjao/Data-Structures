#include "headersWORK.h"


int main()//(int argc, char const *argv[])
{

	Fila *F;
	int menu;
	do
	{
		printf("\n\n ***** MENU *****");	
		printf("\n 1: Create a Queue");	
		printf("\n 2: Display the Queue");	
		printf("\n 3: Add a File at the Pressing Queue");
		printf("\n 4: File Ready to Impress");	
		printf("\n 5: Destroy the entire Queue");	
		printf("\n 6: EXIT");	
		printf("\n\n Enter your option : ");	
		scanf("%d", &menu);
		switch(menu)
		{
			case 1:

				system("clear");
				printf("Print Queue Initializing\n" );
				criaFila(&F);
				break;
			case 2:
				system("clear");
				printf("Printing the Queue Files:\n");
				mostraFila(&F);
				break;
			case 3:
				system("clear");
				pedidoDeimpressao(&F);
				break;
			case 4:
				system("clear");
				impressoraPronta(&F);
				break;
			case 5:
				system("clear");
				Destroy(&F);
				break;
		}
	}while(menu != 6);

	printf("Exiting\n");

	return 0;
}
