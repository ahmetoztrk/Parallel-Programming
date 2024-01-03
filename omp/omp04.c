#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main (int argc, char *argv[]) 
{
        int nthreads, tid, i;
		int n=12;
        int array[12]={3,6,9,12,15,7,8,2,20,5,1,23};
        #pragma omp parallel  private(nthreads, tid, i)
        {               
			 tid = omp_get_thread_num();
                	printf("Th:%d\n",tid);
        	#pragma omp for schedule(static, 3) 
	                for(i=0;i<n;i++){
                                printf("%d\n",array[i]);
                         }
        }
return 0;
}
