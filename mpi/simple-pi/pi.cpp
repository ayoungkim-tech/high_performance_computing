#include <cstdio>
#include <cmath>
#include <mpi.h>

constexpr int n = 840;

int main(int argc, char** argv)
{

  printf("Computing approximation to pi with N=%d\n", n);

  int istart1 = 1;
  int istop1 = n/2;
  int istart2 = istop1 + 1;
  int istop2 = n;

   int ntasks, myid;
   MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

  double pi, sub_pi1, sub_pi2 = 0.0;

  if (myid == 0)
 {
      for (int i=istart1; i <= istop1; i++)
      {
        double x = (i - 0.5) / n;
       sub_pi1 += 1.0 / (1.0 + x*x);
      }
     MPI_Send(&sub_pi1,1,  MPI_DOUBLE, 1,1, MPI_COMM_WORLD);
  }
  else if (myid == 1)
 {
      for (int i=istart2; i <= istop2; i++)
      {
       	double x = (i - 0.5) / n;
       sub_pi2 += 1.0 / (1.0 + x*x);
      }
      MPI_Recv(&sub_pi1,1, MPI_DOUBLE, 0,1, MPI_COMM_WORLD, &status);
      pi = sub_pi2 + sub_pi1;

      pi *= 4.0 / n;
      printf("Approximate pi=%18.16f (exact pi=%10.8f)\n", pi, M_PI);
 }
}
   

