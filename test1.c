#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	char c = 'a';
	if(rank == 0){
		MPI_Send(&c, 1, MPI_CHAR, 1, 1, MPI_COMM_WORLD);
		printf("Sent %c from %d\n", c, rank);

	}else{

		MPI_Recv(&c, 1, MPI_CHAR, 0,1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Received %c from %d\n",c, rank);

	}


	MPI_Finalize();
}
