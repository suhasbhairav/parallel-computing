#include <stdio.h>
#include <mpi.h>

int main( int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int token = 100;
//	MPI_Send(&token, 1, MPI_INT, (rank + 1) %size, 0, MPI_COMM_WORLD);
//	printf("Sent %d from process %d\n", token, (rank+1)%size);	
	if(rank != 0){
		MPI_Recv(&token, 1, MPI_INT, (rank - 1), 0, MPI_COMM_WORLD,
			 MPI_STATUS_IGNORE);
		printf("Process %d received %d from process %d\n",rank, token, (rank - 1));
	}else{
		token = 100;

	}
	
	MPI_Send(&token, 1, MPI_INT, (rank+1)%size, 0, MPI_COMM_WORLD);
	printf("Process %d Sent %d to process %d\n", rank, token, (rank+1)%size);
	if(rank == 0){
		MPI_Recv(&token, 1, MPI_INT, size-1, 0, MPI_COMM_WORLD,
			 MPI_STATUS_IGNORE);
		printf("Process %d Received %d from process %d\n",rank, token, size-1);		

	}
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();
	return 0;

}
