#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	MPI_Comm myComm, firstComm, secondComm;
	
	int size, rank, membershipKey;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	membership = rank % 3;
	MPI_Comm_split(MPI_COMM_WORLD, membershipKey, rank, &myComm);

	if(membershipKey == 0){
		MPI_Intercomm_create(MPI_COMM_WORLD, );
	}




	MPI_Finalize();
	return 0;
}
