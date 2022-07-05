#include <cstdio>
#include <omp.h>
int main()
{

    int threads_num, thread_id;
 
    printf("Hello world!\n");

#pragma omp parallel
    {
        thread_id = omp_get_thread_num();
        threads_num = omp_get_num_threads();
        printf("hello from %i \n", thread_id);
    }
    printf("There are %i threads\n", threads_num);
    return 0;
}
