#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[5];
long int shared_var = 10;


void* mutiply_shared_var(void *arg)
{


unsigned long i = 0;

int thread_id = (int)pthread_self();

shared_var = shared_var * thread_id;


for(i=0; i<(0xFFFFFFFF);i++);

printf("\n Thread %d has finished multiplying\n", thread_id);

return NULL;
}

int main(void)
{
int i = 0;
int val;

while(i < 5)
{
val = pthread_create(&(tid[i]), NULL, &mutiply_shared_var, NULL);
if (val != 0)
printf("\nThread can't be created :[%s]", strerror(val));
i++;
}

pthread_join(tid[0], NULL);
pthread_join(tid[1], NULL);
pthread_join(tid[2], NULL);
pthread_join(tid[3], NULL);
pthread_join(tid[4], NULL);

printf("\n Shared variable value %li \n", shared_var);

return 0;
}