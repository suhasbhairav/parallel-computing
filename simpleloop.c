#include <stdio.h>
#include <mpi.h>

int main(int argc, char*argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int i=0;
	for(i=0;i<10;i++){
		printf("Process %d - size %d\n", rank, size);
	}

	MPI_Finalize();
	return 0;
}
