#include<stdio.h>
#include<mpi.h>
#include <stdlib.h>
int main(int argc, char *argv){
	int rank, size;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	int *in, *out;
	int in_arr[5]={10,20,30,40,50};
	int out_arr[5]={0,0,0,0,0};
	int result;
	int sol[5] = {0,0,0,0,0};	
	in = (int *)malloc(100*sizeof(int));
	out = (int *)malloc(100 * sizeof(int));
	int j;
	for(j=0;j<5;j++){
		*(in + j) = j*j;
	}
	MPI_Allreduce(in, out, 5, MPI_INT, MPI_SUM, MPI_COMM_WORLD );
	
	int i;
	for(i=0;i<5;i++){
		printf("In:%d\t", *(in + i ));
		printf("Out:%d\n",*(out + i));
	}
	printf("%d\n", result);




	MPI_Finalize();
	return 0;
}
