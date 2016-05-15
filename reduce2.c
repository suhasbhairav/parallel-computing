#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	int result;
	
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int arr[10] = {1,10,2,3,4,5,6,7,8,9};
	int elements_per_proc = 10/size;
	int partres[elements_per_proc];
	int subarr[elements_per_proc];
	int localmin,i;
	MPI_Scatter(arr, elements_per_proc,MPI_INT ,subarr, elements_per_proc, MPI_INT, 0, MPI_COMM_WORLD);

	localmin = subarr[0];
	for(i=1;i<elements_per_proc;i++){
		if(subarr[i]<localmin){
			localmin = subarr[i];
		}
	}
	MPI_Reduce(&localmin, &result, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
	printf("Result:%d\n", result);

	MPI_Finalize();
	return 0;

}
