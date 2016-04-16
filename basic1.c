#include <stdio.h>
#include <mpi.h>
int main(int arc, char *argv){
	
	int rank, size;
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); /* Get current Process ID */
	MPI_Comm_size(MPI_COMM_WORLD, &size); /* Get Number of Processes */
	printf("Hello World from process %d of %d\n", rank, size);
	MPI_Finalize();

	return 0;
}
