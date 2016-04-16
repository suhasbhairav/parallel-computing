#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv){

	int rank, size;
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int i=0;
	for(i=0;i<108;i++){
		printf("Loop i:%d using process %d\n",i, rank);		
	}
	MPI_Finalize();

	return 0;
}
