  /* Two in One*/
#include <stdio.h>
#include <mpi.h>
#define SIZE 10000
int main (int argc, char **argv) {
  
    int myrank,i;
    MPI_Status status;
    double a[SIZE],b[SIZE];

    MPI_Init(&argc, &argv);  /* Initialize MPI */
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank); /* Get rank */
    if( myrank == 0 ) {       
        for(i=0;i<SIZE;i++)
            a[i]=i;
        MPI_Sendrecv(a, SIZE, MPI_DOUBLE, 1, 17, b, SIZE, MPI_DOUBLE, 1, 18,MPI_COMM_WORLD, &status);
//        for(i=0;i<SIZE;i++)
//            printf("Proc (%d):%f\n",myrank,b[i]);


    }
    else if( myrank == 1 ){   
        for(i=0;i<SIZE;i++)
            b[i]=i*i;

      MPI_Recv( a, SIZE, MPI_DOUBLE, 0, 17, MPI_COMM_WORLD, &status );   
      MPI_Send( b, SIZE, MPI_DOUBLE, 0, 18, MPI_COMM_WORLD );
//        for(i=0;i<SIZE;i++)
//            printf("Proc (%d):%f\n",myrank,a[i]);
    }
            printf("Proc ID:%d\n",myrank);

    MPI_Finalize();          /* Terminate MPI */
    return 0;
  
}
