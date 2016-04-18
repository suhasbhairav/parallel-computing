#include <stdio.h>
#include <mpi.h>

int main( int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	int number;
	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0){
		number = 100;
		MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf("Process 0 sent 100 to Process 1\n");

		number = 108;
		MPI_Send(&number, 1, MPI_INT, 2, 300, MPI_COMM_WORLD);
		printf("Process 0 sent 108 to Process 2\n");

	}else if(rank == 1){
		MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Process 1 received 100 from Process 0\n");
	
	}else if( rank ==2 ){
		MPI_Recv(&number, 1, MPI_INT, 0, 300, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Process 2 received 108 from Process 0\n");

	}





	MPI_Finalize();
	return 0;
}

