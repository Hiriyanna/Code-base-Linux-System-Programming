#include<stdio.h>
#include<sys/types.h>
#include <signal.h>

void sig_handler1(int num)
{
		printf("You are here becoz of signal:%d\n",num);	
			signal(SIGQUIT,SIG_DFL);
}
void sig_handler(int num)
{
		printf("\nHi! You are here becz of signal:%d\n",num);
}
int main()
{
	signal(SIGINT,sig_handler1);
	signal(SIGQUIT,sig_handler);
	while(1)
	{
		printf("Hello\n");
	//	sleep(2);
	}
				 
}
