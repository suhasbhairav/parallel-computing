#include<mpi.h>
#include<stdio.h>
int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int arr[10]={2,1,4,3,6,5,8,7,10,9};
	int localmax;
	int elements_per_process = 10/size;
	int sub_arr[elements_per_process];
	int part_result[elements_per_process];
	int result;
	MPI_Scatter(arr, elements_per_process, MPI_INT, sub_arr, elements_per_process, MPI_INT, 0, MPI_COMM_WORLD);

	localmax = sub_arr[0];
        int i;
	for(i=0;i<elements_per_process;i++){
		if(localmax <= sub_arr[i]){
			localmax = sub_arr[i];
		}
	}
	MPI_Reduce(&localmax, &result, 1, MPI_INT, MPI_MAX,0, MPI_COMM_WORLD);
	printf("Result:%d\n", result);

	MPI_Finalize();
	return 0;
}
