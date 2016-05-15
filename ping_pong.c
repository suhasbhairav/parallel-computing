#include <stdio.h>
#include <mpi.h>

int main( int argc, char *argv){
	int rank, size, count = 0, p_rank;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	p_rank =  (rank + 1)%2;
	while(count < 10){
		if(rank == count % 2){
			count++;
			MPI_Send(&count, 1, MPI_INT, p_rank, 0, MPI_COMM_WORLD);
			printf("Sending %d from %d\n", count, rank);
		}else{
			MPI_Recv(&count, 1, MPI_INT, p_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("Receiving %d from %d\n", count, rank);
			
		}
	}

	MPI_Finalize();
	return 0;

}
