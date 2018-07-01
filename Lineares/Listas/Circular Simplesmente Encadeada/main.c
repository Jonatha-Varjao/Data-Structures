#include "headers.c"

int main()
{
	lista l;

	createList(&l);
	insertHead(&l,5);
	insertHead(&l,6);
	insertHead(&l,7);
	insertHead(&l,8);
	insertHead(&l,9);
	insertHead(&l,10);
	insertHead(&l,11);
	printList(&l);

	return 0;
}

