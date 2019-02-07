#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define No_of_threads 3 // no of threads to be processed 
void*func_name(void*threadnumber)
{
	long thread_no;
	thread_no=(long)threadnumber;
	printf("Hai Gowda %ld\n",thread_no);
	pthread_t self_id;
	self_id=pthread_self();
	printf(" hai, i am a thread. my id=%u\n",self_id);
	pthread_exit(NULL);
}

int main()
{
	pthread_t id[No_of_threads];
	//int ret;
	long t;
	for (t=0;t< No_of_threads;t++)
	{
		printf("thread %d  is created\n",t+1);
		pthread_create(&id[t],NULL,&func_name,(void*)t);
		//pthread_join(id[t], NULL);
		pthread_detach(id[t]);
	}
//	pthread_exit(NULL);
	return 0;
}
