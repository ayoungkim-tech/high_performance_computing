#include <cstdio>

int main(void)
{
    // shared
    int var1 = 1, var2 = 2;

    /* TODO:
     *   Test the effect of different data sharing clauses here
     */
    #pragma omp parallel firstprivate (var1, var2)
    //#pragma omp parallel
    {
        // private
        //int var1 = 3, var2 = 4;

        printf("Region 1: var1=%i, var2=%i\n", var1, var2);
        var1++;
        var2++;
    }
    printf("After region 1: var1=%i, var2=%i\n\n", var1, var2);

    return 0;
}
