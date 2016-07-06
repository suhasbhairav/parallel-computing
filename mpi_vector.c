#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int size, rank;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int length = 8;
	int i,j;
	int x[length][length];
	int y[length][length];
	MPI_Datatype new_type;
	for(i=0;i<length;i++){
		for(j=0;j<length;j++){
			x[i][j] = i*j;
			y[i][j] = -1;
		}
	}
	printf("Input matrix\n");
	for(i=0;i<length;i++){
		for(j=0;j<length;j++){
			printf("%d\t", x[i][j]);
		}
		printf("\n");
	}
	
	/*
	int count = 8;
	int blocklength = 2;
	int stride = 8;

	MPI_Type_vector(count, blocklength, stride, MPI_INT, &new_type);
	MPI_Type_commit(&new_type);

	if(rank == 0){
		MPI_Send(&x[0][3],1, new_type, 1, 1, MPI_COMM_WORLD );	
	}else{
		MPI_Recv(&y[0][3],1, new_type, 0,1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	
	}

	*/

	int count = 8;
	int blocklength = 4;
	int stride = 8;

	MPI_Type_vector(count, blocklength, stride, MPI_INT, &new_type);
	MPI_Type_commit(&new_type);

	if(rank == 0){
		MPI_Send(&x[0][2], 1, new_type, 1,1, MPI_COMM_WORLD);
	}else{
		MPI_Recv(&y[0][2],1, new_type, 0,1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	}
	
	printf("Resultant matrix:\n");
	for(i=0;i<length;i++){
		for(j=0;j<length;j++){
			printf("%d\t", y[i][j]);
		}
		printf("\n");

	}




	MPI_Finalize();
	return 0;
}
