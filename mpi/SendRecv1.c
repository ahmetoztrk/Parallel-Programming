  /* simple send and receive */
#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <unistd.h>
int main (int argc, char **argv) {
    int myrank,size;
    MPI_Status status;
    MPI_Request req;
    int a[10]={2,6,4,5,2,8,7,5,1,7};
	int  b[10];
	MPI_Init(&argc, &argv);  /* Initialize MPI */
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank); /* Get rank */
	MPI_Comm_size(MPI_COMM_WORLD, &size);
    	if( myrank == 0 ){       /* Send a message */
		for(int i=1;i<size;i++){
      			MPI_Send( a, 10, MPI_INT, i, 17, MPI_COMM_WORLD );
      		//	MPI_Isend( a, 100, MPI_DOUBLE, i, 17, MPI_COMM_WORLD,&req );
			printf("Process 0: Send the message to %d\n",i);
			 for(int j=0;j<10;j++){
                		printf("%d--",b[j]);
        		}
        		printf("\n");
		}
		printf("Message Sending is over\n");
    }
    else {   /* Receive a message */
      MPI_Recv(b, 10, MPI_INT, 0, 17, MPI_COMM_WORLD, &status );   
     // MPI_Irecv( a, 100, MPI_DOUBLE, 0, 17, MPI_COMM_WORLD, &req );   
      printf("Process %d: Received the message\n",myrank);
	sleep(2);

		 for(int j=0;j<10;j++){
                        printf("%d--",b[j]);
                     }

                      printf("\n");

    }

    MPI_Finalize();          /* Terminate MPI */

}
