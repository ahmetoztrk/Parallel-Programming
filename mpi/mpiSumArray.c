#include "mpi.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#define MAXSIZE 100

int main(int argc, char **argv)
{
	int myid, numprocs;
	int data[MAXSIZE], i, x, low, high, myresult=0, result;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);

	if(0 == myid) {
		for(i=0; i<MAXSIZE; i++) {
			data[i]=i;
		}
	}
	MPI_Bcast(data, MAXSIZE, MPI_INT, 0, MPI_COMM_WORLD);
	x = MAXSIZE/numprocs;	/* must be an integer */
	low = myid * x;
	high = low + x;
	for(i=low; i<high; i++) {
		myresult += data[i];
	}
	printf("I got %d from %d\n", myresult, myid);

	MPI_Reduce(&myresult, &result, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

	if(0 == myid) {
		printf("The sum is %d.\n", result);

	}

	
	MPI_Finalize();
}
