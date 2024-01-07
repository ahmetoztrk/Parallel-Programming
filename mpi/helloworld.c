#include <stdio.h>
#include "mpi.h"

int main( int argc, char *argv[] )
{
    char name[BUFSIZ];
    int  resultlength, rank, size;
    double sTime, eTime;
/* Initialize the MPI execution environment */
    MPI_Init( &argc, &argv );
    sTime=MPI_Wtime();
/* Determines the size of the group */
    MPI_Comm_size( MPI_COMM_WORLD, &size );
/* Determines the rank of the calling process */
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
 
/* Returns the processor name */
    MPI_Get_processor_name(name, &resultlength); 
    printf( "Processor name: %s (%d of %d) \n", name, rank, size);
    eTime=MPI_Wtime();
    if (rank == 0 ) /* Let's called "master */
        printf( "It takes: %lf (seconds)\n",eTime-sTime);
/* Terminates MPI execution environment */
    MPI_Finalize();
        
    return 0;
}
