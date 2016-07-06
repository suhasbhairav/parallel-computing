#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	char varChar[] = {'T','E', 'S', 'T'};
	int i;
	if(rank == 0){
		for(i=0;i<4;i++){
			MPI_Send(&varChar[i], 1,MPI_CHAR, 1,1, MPI_COMM_WORLD);
			printf("i=%c\t",varChar[i]);
		}
	}else{
		for(i=0;i<4;i++){
		MPI_Recv(&varChar[i], 1, MPI_CHAR,0,1,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("i=%c\t",varChar[i]);
	}
	}



	MPI_Finalize();
	return 0;
}
