#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int count = 8;
	int blocklength = 4;
	
	int stride = 8;
	MPI_Datatype new_type;
	
	int length = 8;
	int i,j;
	int mat[length][length];
	int res[length][length];
	printf("\n\n");
	for(i=0;i<length;i++){
		for(j=0;j<length;j++){
			mat[i][j]= i*j;
			res[i][j] = -1;
			printf("%d\t", mat[i][j]);
		}
		printf("\n");	

	}
	printf("\n\n");
	MPI_Type_vector(count, blocklength, stride, MPI_INT, &new_type);
	MPI_Type_commit(&new_type);
	if(rank == 0){
		MPI_Send(&mat[0][0],1, new_type, 1, 1, MPI_COMM_WORLD);
	}else{
		MPI_Recv(&res[0][0],1, new_type, 0,1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

	}
	for(i=0;i<length;i++){
		for(j=0;j<length;j++){
			printf("%d \t", res[i][j]);

		}
		printf("\n");
	}
	

	MPI_Finalize();
	return 0;
}
