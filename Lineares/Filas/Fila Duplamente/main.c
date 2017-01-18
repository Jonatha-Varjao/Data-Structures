#include "headers.h"

int main()//(int argc, char const *argv[])
{
	//TODO CODE HERE//
	fila *Queue;
	createQeue(&Queue);
	queue(&Queue,5);
	queue(&Queue,8);
	printQueue(&Queue);
	Destroy(&Queue);
	printQueue(&Queue);

	return 0;
}

