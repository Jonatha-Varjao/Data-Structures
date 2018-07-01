#include "headers.c"
int main()//int argc, char const *argv[])
{
	lista L;
	createLista(&L);
	insertHead(&L,20);
	insertHead(&L,30);
	insertHead(&L,40);
	removeTail(&L);
	
	printLista(&L);
	//printListaReverse(&L);
	
	return 0;
}
