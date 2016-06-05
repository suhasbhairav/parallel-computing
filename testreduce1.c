#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int arr[5] = {2,4,1,3,5};
	int i, local_min,elements_per_process,result;
	elements_per_process = 5/size;
	int sub_array[elements_per_process];
	
	MPI_Scatter(arr, elements_per_process, MPI_INT, sub_array, elements_per_process, MPI_INT, 0, MPI_COMM_WORLD);

	local_min = sub_array[0];
	for(i=0;i<elements_per_process;i++){
		if(sub_array[i] < local_min){
			local_min = sub_array[i];
		}
	}

	MPI_Reduce(&local_min, &result, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
	printf("Minimum: %d\n", result);





	MPI_Finalize();
	return 0;
}
