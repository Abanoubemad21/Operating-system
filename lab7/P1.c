#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void * Rand_num (void * paramter)
{
	int num;
    num = rand() % 10;
    return (int *) num;
}
int main()
{
	int sum , ran[5];
	pthread_t thread[5];
	for (int i=0; i < 5; i++) {
		pthread_create (&thread[i], 0, Rand_num, 0);
		pthread_join(thread[i], (void**)&ran[i]);
		sum += ran[i];
	}
	printf("The result = %d", sum);
}