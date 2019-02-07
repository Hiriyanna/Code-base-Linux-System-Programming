#include <stdio.h>   //for printf
#include <signal.h>  //for signal function
#include <unistd.h>  //for sleep

//it will raise try to access inactive memory

void sig_handler(int num)
	{
          printf("signal num=%d\n",num);
        }
int main()
{
signal(SIGSEGV,sig_handler);	
int *ptr = NULL;
printf("%d", *ptr);

}
