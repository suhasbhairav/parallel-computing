#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int length = 8;
	int mat[length][length];
	int res[length][length];
	int i,j;
	printf("\n\n");
	for(i=0;i<length;i++){
		for(j=0;j<length;j++){
			mat[i][j] = i+j;
			res[i][j] = -1;
			printf("%d\t", mat[i][j]);

		}
		printf("\n");

	}

	MPI_Datatype new_type;
	int count = 8;
	//int block_arr[8]={1,2,3,4,5,6,7,8};
	int block_arr[8] = {8,7,6,5,4,3,2,1};
	int disp[8]={0,9,18,27,36,45,54,63};

	MPI_Type_indexed(count, block_arr, disp, MPI_INT, &new_type);
	MPI_Type_commit(&new_type);

	printf("\n\n");
	if(rank == 0){
		MPI_Send(&mat[0][0], 1, new_type,1,1, MPI_COMM_WORLD);
	}else{
		MPI_Recv(&res[0][0],1,new_type,0,1,MPI_COMM_WORLD, MPI_STATUS_IGNORE);

	}
	for(i=0;i<length;i++){
		for(j=0;j<length;j++){
			printf("%d\t", res[i][j]);
		}
		printf("\n");
	}


	printf("\n\n");

	MPI_Finalize();
	return 0;
}
