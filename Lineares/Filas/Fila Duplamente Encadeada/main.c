#include "headers.c"

int main()
{
	
	fila Queue;
	createQeue(&Queue);
	queue(&Queue,5);
	queue(&Queue,8);
	printQueue(&Queue);
	Destroy(&Queue);
	printQueue(&Queue);

	return 0;
}

