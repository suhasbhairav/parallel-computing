#include<mpi.h>
#include<stdio.h>
#include <time.h>
#include<math.h>
#include <stdlib.h>

int main(int argc, char **argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	int MAX_NUMBERS = 100;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int numbers[MAX_NUMBERS];
	int number_amount;
	if(rank == 0){
		srand(time(NULL));
		number_amount = ( rand() / (float)RAND_MAX) * 100;
		MPI_Send(numbers, number_amount, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf("Sent %d numbers\n", number_amount);
	}else{
		MPI_Status status;
		MPI_Recv(numbers, 100, MPI_INT, 0,0, MPI_COMM_WORLD, &status);
		MPI_Get_count(&status, MPI_INT, &number_amount);
		printf("Received: %d from source:%d having tag:%d\n", number_amount, status.MPI_SOURCE, status.MPI_TAG);
	}

	MPI_Finalize();
	return 0;
}
