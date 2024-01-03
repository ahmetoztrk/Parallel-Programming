#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main (int argc, char *argv[]) 
{
        int nthreads, tid, i;
        /* Start parallel region */
        int n;
	n=atoi(argv[1]);
	int sum=0;
        #pragma omp parallel private(nthreads, tid) shared(sum) 
        {	
		#pragma omp for
		for(i=0;i<n;i++){
			sum+=i;
	//	 	printf("T=%d\n",sum);		
		}	
	}
	printf("Sum=%d\n",sum);
return 0;

}
