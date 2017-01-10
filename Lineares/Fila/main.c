#include "headers.h"

int main(int argc, char const *argv[])
{
	//TODO CODE HERE//
	fila *Queue;
	//deQueue(&Queue);
	createQeue(&Queue);
	queue(&Queue, 3);
	queue(&Queue,5);
	queue(&Queue,7);
	//printQueue(&Queue);
	deQueue(&Queue);
	printQueue(&Queue);

	printf("HELLO WORLD\n");
	return 0;
}
