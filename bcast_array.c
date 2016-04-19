#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int number[4] = {10,20,30,40};

	MPI_Bcast(&number, 4, MPI_INT, 0, MPI_COMM_WORLD);
	
	printf("Receiver:%d ==> Value:%d\t%d\t%d\t%d\n", rank, 
			number[0], number[1], number[2], number[3]);

	MPI_Finalize();
	return 0;
}
