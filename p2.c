#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	int val = 1000,i;
	int arr[3] = {1,2,3};
/*	if(rank == 0){
		MPI_Send(arr, 3, MPI_INT, 1, 1, MPI_COMM_WORLD);
		for(i=0;i<3;i++){
			printf("Sent %d from %d\n", arr[i], rank);
		}
//		printf("Sent %d from %d\n", val, rank);
	}else{
		MPI_Recv(arr, 3, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		//printf("Received %d from %d\n", val, rank);
		for(i=0;i<3;i++){
			printf("Received %d from %d\n", arr[i], rank);
		}
	}
*/

	MPI_Bcast(&val, 1, MPI_INT, 0, MPI_COMM_WORLD);
	printf("Process %d received %d\n ", rank, val);

	MPI_Finalize();
	return 0;
}
