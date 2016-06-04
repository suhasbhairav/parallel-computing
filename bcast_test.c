#include<mpi.h>
#include <stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int val;
	if(rank == 0){

		val = 100;	
	}
	MPI_Bcast(&val, 1, MPI_INT, 0, MPI_COMM_WORLD);
	printf("Sent : %d\t Rank:%d\n", val, rank);

	MPI_Finalize();
}
