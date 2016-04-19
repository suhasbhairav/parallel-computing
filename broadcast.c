#include <stdio.h>
#include <mpi.h>

int main( int argc, char **argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int number;
	if(rank == 0){
		number = 108;
	}
	MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);

	printf("Receiver : %d ==> Value : %d\n", rank, number);

	MPI_Finalize();
	return 0;
}
