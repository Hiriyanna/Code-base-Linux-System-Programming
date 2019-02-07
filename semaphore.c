#include<stdio.h>     
#include<errno.h>     
#include<sys/shm.h> 
#include<sys/wait.h>
#include<semaphore.h>     
#include<stdlib.h>     
#include<fcntl.h> 
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int i, shmid;
	int *p;
	pid_t pid;
	key_t key= 123456789;
	sem_t*sem;
	unsigned int n;
	unsigned int value;


// initialize, shared memory usage.
 shmid=shmget(key,sizeof(int),IPC_CREAT|0666);
 if (shmid<0)
 {
 	 printf("sorry");
	 exit(1);
 }
        // attachment
	 p=(int *)shmat(shmid,NULL,0);
	 *p=0;
	 if (p==NULL)
	 {
	 	printf("sorry");
		exit(1);
	 }
	 else
		 printf("p=%d is allocated memory.\n\n",*p);
// forking and semaphore count declaration.
printf("enter the no of chiildren u want to fork?\n");
printf("the count:");
scanf("%u",&n);
printf("enter semphore value\n");
printf("semaphore value:");
scanf("%u",&value);
//semaphore initialization
sem =sem_open("Sem_Here",O_CREAT|O_EXCL,0666, value);
sem_unlink("Sem_Here");
printf("semaphore initialized.\n\n");
// forking
for (i=0;i<n;i++)
{
	pid=fork();
	if(pid<0)
		printf("error");
	else if(pid==0) //child process
		break;
}
if(pid!=0) // parent process
{
while(pid=waitpid(-1,NULL,0))
{
	if (errno=ECHILD)
		break;
}
printf("all the children exited.\n");
shmdt(p);
shmctl(shmid,IPC_RMID,0);
sem_destroy(sem);
exit(1);
}
else
{
	sem_wait(sem);
	printf(" child(%d) is in critical section.\n",i);
		sleep(1);
	*p+=i%3;
	printf("child(%d) new value of *p=%d.\n",i, *p);
	sem_post(sem);
	exit(1);
}
}

