#include "headers.c"
int main()
{
	
	lista L;
	createLista(&L);
	insertList(&L, 10);
	insertList(&L, 9);
	insertList(&L, 8);
	insertList(&L, 7);
	insertList(&L, 6);
	insertList(&L, 5);
	insertList(&L, 4);
	insertList(&L, 3);
	printLista(&L);
	emptyList(&L);
	printLista(&L);
	return 0;
}
