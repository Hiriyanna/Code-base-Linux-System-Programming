#include<stdio.h>
#include<pthread.h>
void * func_name(void * a)
{
printf("Hai Gowda Second thread");
}
int main()
{
pthread_t id;
pthread_create(&id,NULL,&func_name,NULL);
printf("Main thread\n");

//pthread_join(id,NULL);
return 0;
}
