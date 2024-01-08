#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank;
    double parameter;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 1) {
        parameter = 3.14;
    }

    MPI_Bcast(&parameter, 1, MPI_DOUBLE, 1, MPI_COMM_WORLD);

    printf("P:%d after broadcasting, the parameter value is %f \n", rank, parameter);

    MPI_Finalize();

    return 0;
}

