#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	MPI_Datatype new_type;
	int i,j,length = 8;
	int x[length][length];
	int y[length][length];
	for(i=0;i<length;i++){
		for(j=0;j<length;j++){
			x[i][j] = i*j;
			y[i][j] = -1;
		}

	}
	printf("Input matrix:\n");
	for(i=0;i<length;i++){
		for(j=0;j<length;j++){
			printf("%d\t", x[i][j]);
		}
		printf("\n");
	}
	/* Lower Triangular Matrix
	int count = length;
	int blocklength[] = {1,2,3,4,5,6,7,8};
	int displ[] = {0,8,16,24,32,40,48,56};
	*/
	
	/* Upper Triangular Matrix
	int count = length;
	int blocklength[] = {8,7,6,5,4,3,2,1};
	int displ[] = {0,9,18,27,36,45,54,63};
	*/

	int count = length;
	int blocklength[] = {1,1,1,1,1,1,1,1};
	int displ[] = {0,9,18,27,36,45,54,63};
	
	MPI_Type_indexed(count, blocklength, displ, MPI_INT, &new_type);
	MPI_Type_commit(&new_type);

	if(rank == 0){
		MPI_Send(&x[0][0],1, new_type, 1,1, MPI_COMM_WORLD);
	}else{
		MPI_Recv(&y[0][0],1, new_type, 0,1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	}
	printf("Resultant matrix:\n");
	for(i=0;i<length;i++){
		for(j=0;j<length;j++){
			printf("%d\t",y[i][j]);
		}
		printf("\n");

	}

	MPI_Finalize();
	return 0;
}
