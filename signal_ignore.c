#include<stdio.h>
#include<sys/types.h>
#include <signal.h>


int main()
{
	signal(SIGINT,SIG_IGN);
	while(1)
	{
		printf("Gowda Dont stop move on\n");
		sleep(2);
	}
	return 0;
}
