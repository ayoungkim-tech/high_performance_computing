#include <cstdio>
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
<<<<<<< HEAD
    int numtasks, rank, namelen;
    char hostname[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);
    MPI_Get_processor_name(hostname, &namelen);
    // TODO: say hello! in parallel
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Get_processor_name(hostname, &namelen);
    printf("Hello!from  %d in processor %s\n ", rank, hostname);
    MPI_Barrier(MPI_COMM_WORLD);
=======
    int numtasks, rank;
    char hostname[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);
    MPI_Get_processor_name(hostname, &len);
    // TODO: say hello! in parallel
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("Hello! %d ", rank)
    MPI_Barrier(comm)
>>>>>>> 07cc20dc5cd5e21eec32c43ff4dad1c8f62a3137
    MPI_Finalize();
}
