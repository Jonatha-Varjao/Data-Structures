#include "headers.h"

int main(int argc, char const *argv[])
{
	stack *P;
	
	int menu;
	do
	{
		printf("\n\n ***** MENU *****");	
		printf("\n 1: Create Stack");	
		printf("\n 2: Display Stack");	
		printf("\n 3: Push");
		printf("\n 4: Pop");	
		//printf("\n 5: Reverse String");	
		printf("\n 5: Delete");
		printf("\n 6: EXIT");	
		printf("\n\n Enter your option: ");	
		scanf("%d", &menu);
		switch(menu)
		{
			case 1:

				system("clear");
				printf("Initializing Stack\n" );
				createStack(&P);
				break;
			case 2:
				system("clear");
				printf("Printing the Stack:\n");
				printStack(&P);
				break;
			case 3:
				system("clear");
				printf("ENTER A CHARACTER\n");
				push(&P);
				break;
			case 4:
				system("clear");
				pop(&P);
				break;
			case 5:
				system("clear");
				deleteStack(&P);
				break;
				
		}
	}while(menu != 6);

	return 0;
}
