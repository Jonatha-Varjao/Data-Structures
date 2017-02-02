#include "headers.h"
int main()//int argc, char const *argv[])
{
	lista L;
	createLista(&L);
	insertHead(&L,30);
	//insertHead(&L,50);
	//insertHead(&L,60);
	printLista(&L);
	printListaReverse(&L);

	return 0;
}
