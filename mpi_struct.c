#include <mpi.h>
#include <stdio.h>


struct Partstruct{
	char a;
	int b[6];
	double c[7];


};
int main(int argc, char *argv){
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	MPI_Datatype type[3] = {MPI_CHAR, MPI_INT, MPI_DOUBLE};
	int blocklength[3] = {1,6,7};
	MPI_Aint disp[3];
	MPI_Datatype new_type;
	
	struct Partstruct partStructure[100];
	disp[0] = &partStructure[0].a - &partStructure[0];
	disp[1] = &partStructure[0].b - &partStructure[0];
	disp[2] = &partStructure[0].c - &partStructure[0];

	MPI_Type_create_struct(3, blocklength, disp, type, &new_type);
	MPI_Type_commit(&new_type);
	

	if(rank == 0){
		MPI_Send(partStructure, 100, new_type, 1, 1, MPI_COMM_WORLD);
	}else{

		MPI_Recv(partStructure, 100, new_type, 0,1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	}


	MPI_Finalize();
	return 0;
}
