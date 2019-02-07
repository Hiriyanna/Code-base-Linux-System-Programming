#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int main (void)
{
int status;
pid_t pid;
pid = waitpid (1742, &status, WNOHANG);
if(pid==-1)
perror("waitpid");
else
{
printf("pid=%d\n",pid);
if(WIFEXITED(status))
printf("Normal termination with exit status=%d\n",WEXITSTATUS(status));
}
}
