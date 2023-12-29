#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	10
int globVar=5;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
void *increment()
{
	pthread_mutex_lock(&lock);
   globVar+=1;
   printf("Incremenet #%d!\n", globVar);
	pthread_mutex_unlock(&lock);
   pthread_exit(NULL);
}
void *decrement()
{
	pthread_mutex_lock(&lock);
   globVar-=1;
   printf("Decrement #%d!\n", globVar);
	pthread_mutex_unlock(&lock);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int ri,rd ;
   long t;
   	for (int i=0;i<NUM_THREADS;i++){
	     printf("In main: Increment \n");
	     ri = pthread_create(&threads[i], NULL, increment, NULL);
	     rd = pthread_create(&threads[i], NULL, decrement, NULL);
     	}
	for (int i=0;i<NUM_THREADS;i++){
		pthread_join(threads[i],NULL);
	}
	
	printf("Global Variable In Main:%d\n",globVar);
   
   pthread_exit(NULL);
}
