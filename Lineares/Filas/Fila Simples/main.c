#include "headers.h"


int main()//(int argc, char const *argv[])
{
	fila *F;
	int menu;
	do
	{
		printf("\n\n ***** MENU *****");	
		printf("\n 1: Create a Queue");	
		printf("\n 2: Display the Queue");	
		printf("\n 3: Add a File");
		printf("\n 4: Add at Head");
		printf("\n 5: Remove at Tail");
		printf("\n 6: Remove a File");	
		printf("\n 7: Search a File");	
		printf("\n 8: Destroy");
		printf("\n 9: Exit");	
		printf("\n\n Enter your option : ");	
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

	printf("Exiting\n");
	
	return 0;
}
