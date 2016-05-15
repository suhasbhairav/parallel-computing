#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int val = 1000;
	MPI_Bcast(&val, 1, MPI_INT, 0, MPI_COMM_WORLD);

	printf("Process %d contains %d\n", rank, val);



	MPI_Finalize();
	return 0;
}
