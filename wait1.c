#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int
 main (void)
{
int status;
pid_t pid;
if (!fork ())
return 1;
pid = wait (&status);
if (pid == -1)
perror("wait");
printf("pid=%d\n", pid);
if(WIFEXITED(status))
printf("Normal termination with exit status=%d\n",WEXITSTATUS(status));
return 
}
