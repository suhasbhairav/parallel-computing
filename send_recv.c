#include <stdio.h>
#include <mpi.h>

int main( int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	int number =0;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0){
		number = 100;
		MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf("Process 0 sent value 100 to process 1\n");
	}else if(rank == 1){
		MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Process 1 received value 100 from process 0\n");
	}
	
	MPI_Finalize();

	return 0;


}
