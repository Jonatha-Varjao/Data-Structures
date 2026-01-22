#include "headers.c"

int main(int argc, char const *argv[])
{
	stack *P;
	char word[100];

	int menu;
	do
	{
		printf("\n\n ***** MENU *****");
		printf("\n 1: Create Stack");
		printf("\n 2: Display Stack");
		printf("\n 3: Push");
		printf("\n 4: Pop");

		printf("\n 5: Delete");
		printf("\n 6: Reverse String");
		printf("\n 7: EXIT");
		if (menu == 6)
			printf("\n\n Enter your String: ");
		else
			printf("\n\n Enter your Option: ");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:

			system("clear");
			printf("Initializing Stack\n");
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
		case 6:
			system("clear");
			printf("ENTER THE STRING\n");
			scanf("%[^\n]s", word);
			printf("%s\n", word);
			int len = strlen(word), i;
			for (i = 0; i <= len; i++)
				push2(word[i]);

			system("clear");

			for (i = 0; i <= len; i++)
				pop2();
			system("clear");
			break;
		}
	} while (menu != 7);

	return 0;
}
