#include <stdio.h>
#include<mpi.h>

int main( int argc, char **argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	char arr[4]={'a','b','c','d'};

	MPI_Bcast(arr, 4, MPI_CHAR, 0, MPI_COMM_WORLD);

	printf("Rank : %d ==> Char : %c %c %c %c\n", rank, arr[0], arr[1], arr[2], arr[3]);

	MPI_Finalize();
	return 0;

}
