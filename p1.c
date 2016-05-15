#include <stdio.h>
#include <mpi.h>


int main(int argc, char *argv){
	int rank, size;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int val = 100;
	if(rank == 0){
		MPI_Send(&val, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
		printf("Sending %d from %d\n", val, rank);
	}else{
		MPI_Recv(&val, 1, MPI_INT, 0,1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Receiving %d from %d\n", val, rank);

	}


	MPI_Finalize();
	return 0;
}
