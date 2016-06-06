#include<mpi.h>
#include<stdio.h>

int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int size;
	int rank;
	
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	
	int server;
	server = size - 1;
	MPI_Group world_group, new_group;
	MPI_Comm_group(MPI_COMM_WORLD, &world_group);
	int ranks[10];
	ranks[0] = server;
	MPI_Comm new_comm;
	MPI_Group_excl(size, 1, ranks, &new_group);
	MPI_Comm_create(size, new_group, &new_comm);
	MPI_Group_free(&world_group);
	MPI_Group_free(&new_group);
	MPI_Comm_free(&new_comm);

	MPI_Finalize();
	return 0;
}
