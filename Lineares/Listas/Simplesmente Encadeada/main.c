#include "headers.h"

int main()
{
	lista *l;
	int menu;	
	int data;
	int pos;
	do
	{
		printf("\n\n ***** MENU *****");	
		printf("\n 1 : Create List");	
		printf("\n 2 : Display List");	
		printf("\n 3 : Insert Head");
		printf("\n 4 : Insert Tail");
		printf("\n 5 : Insert Any Pos");
		//printf("\n 6 : Insert in Order");
		printf("\n 6 : Remove Head");
		printf("\n 7 : Remove Tail");		
		printf("\n 8 : Remove Any Pos");
		printf("\n 9 : Destroy List");
		printf("\n 10: Search Element");
		printf("\n 11: Sort the List");	
		printf("\n 0 : EXIT\n");		
		scanf("%d",&menu);
		switch(menu)
		{
			case 1:
				system("clear");
				printf("Initializing List\n" );
				createList(&l);
				break;
			case 2:
				system("clear");
				printf("Printing the List:\n");
				printList(&l);
				break;
			case 3:
				system("clear");		 //THE BEST WAY IS TO CAPTURE THE DATA INSIDE THE FUNCTION....
				printf("INSERT DATA:\n");//MORE ATTRACTIVE AND A GOOD CODING MANNERS
				scanf("%d", &data);		 //AS WORKING WITH LEGACY THINGS....BUT I'M LAZY HIHIXD
				insertHead(&l,data);
				break;
			case 4:
				system("clear");
				printf("INSERT DATA:\n");
				scanf("%d", &data);
				insertTail(&l,data);
				break;
			case 5:
				system("clear");
				printf("INSERT DATA:\n");
				scanf("%d", &data);
				printf("INSERT POS:\n");
				scanf("%d", &pos);
				insertAny(&l,data,pos);
				break;
			// case 6:
			// 	system("clear");
			// 	printf("INSERT DATA:\n");
			// 	scanf("%d", &data);
			// 	insertOrdered(&l,data);
			// 	break;
			case 6:
				system("clear");
				removeHead(&l);
				break;
			case 7:
				system("clear");
				removeTail(&l);
				break;
			case 8:
				system("clear");
				printf("INSERT POS:\n");
				scanf("%d", &pos);
				removeAny(&l,pos);
				break;
			case 9:
				system("clear");
				Destroy(&l);
				break;
			case 10:
				system("clear");
				printf("INSERT DATA TO SEARCH:\n");
				scanf("%d", &data);
				Search(&l,data);
				break;	
			case 11:
				system("clear");
				SSortList(&l);
				break;							
		}
	}while(menu != 0);

	return 0;
}

