#include<stdio.h>
#include<pthread.h>
#define C 3 // no of threads to be processed 
void * func_name(void * threadnumber)
{
printf("Hai Gowda Second thread\n");
pthread_t self_id;
self_id=pthread_self();
printf("thread id=%u\n",self_id);
pthread_exit(NULL);
}

int main()
{
pthread_t id[C];
int t;
for(t=0;t<C;t++)
{

pthread_create(&id[t],NULL,&func_name,(void *)t);

printf("Main thread\n");
}
pthread_join(id,NULL);
return 0;
}
