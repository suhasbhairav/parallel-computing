#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int val = 100;
	if(rank == 0){
		MPI_Send(&val, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
		printf("Sent %d from %d\n", val, rank);
	}else{
		MPI_Recv(&val, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
		printf("Received %d from %d\n", val, rank);

	}


	MPI_Finalize();




}
