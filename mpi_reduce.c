#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int *sendbuf, *recvbuf;
	int i;
	for(int i=0;i<100;i=i*2){
		sendbuf= (int *)malloc(i*sizeof(int));
		recvbuf=(int*)malloc(i*sizeof(int));
		for()


	}






	MPI_Finalize();
}
