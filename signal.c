#include<stdio.h>
#include<sys/types.h>
#include <signal.h>

void sig_handler1(int num)
{
		printf("You are here becoz of signal:%d\n",num);	
}

int main()
{
	signal(SIGALRM,sig_handler1);
	while(1)
	{
		printf("Gowda\n");
		sleep(2);
	}
	return 0;
}
