#include<stdio.h>     
#include<stdlib.h>     
#include<sys/shm.h> 
#include<string.h>

#define size 1024
int main()
{
int retval, shmid;
void *memory=NULL;
char *p;
key_t key=123456789;

// initialize
shmid=shmget(key,size,IPC_CREAT|0666);
if (shmid<0)
{
	printf("sorry");
	exit(1);
}
//attachment
memory=shmat(shmid,NULL,0);
if (memory==NULL)
{
	printf("sorry");
	exit(1);
}
p=(char*)memory;
memset(p,'\0',10);
memcpy(p,"hiriyanna",10);
printf("msg is %s",p);
//deatach
retval=shmdt(p);
return 0;
}

