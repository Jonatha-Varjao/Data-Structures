#include "headers.h"

int main()
{
	//TODO CODE HERE//
	fila *Queue;
	int menu;
	do
	{
		printf("\n\n ***** MENU *****");	
		printf("\n 1: Create a Queue");	
		printf("\n 2: Display the Queue");	
		printf("\n 3: Add to the Queue");
		printf("\n 4: Search Queue");	
		printf("\n 5: Remove First");
		printf("\n 6: Remove Tail");
		printf("\n 7: Destroy the Priority Queue");	
		printf("\n 8: EXIT");
		printf("\n\n Enter your option: ");	
		scanf("%d", &menu);
		switch(menu)
		{
			case 1:
				system("clear");
				printf("Initializing Priority Queue\n");
				createQeue(&Queue);
				break;
			case 2:
				system("clear");
				printf("All Files Display\n");
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
	printf("EXITING\n");
	return 0;
}

