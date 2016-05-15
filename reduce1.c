#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	

	MPI_Comm_size(MPI_COMM_WORLD, &size );
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int arr[8]={10, 20, 30, 40,100,5,25,17};
	int elements_per_proc = 8/size;
	int subarr[elements_per_proc];
	int partres[elements_per_proc];

	MPI_Scatter(arr, elements_per_proc, MPI_INT, subarr, elements_per_proc, MPI_INT, 0, MPI_COMM_WORLD);
	
	int localmax = subarr[0];
	int i;
	for(i=1;i<elements_per_proc;i++){
		if(subarr[i] > localmax){
			localmax= subarr[i];
		}
	}
	int result;
	MPI_Reduce(&localmax, &result, 1,MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

	printf("Result:%d\n", result);


	MPI_Finalize();
	return 0;
}
