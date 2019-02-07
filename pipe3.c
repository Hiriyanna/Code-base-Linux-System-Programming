#include<stdio.h>
#include<unistd.h>

int main() 
{
   int pipefds[2];
   int returnstatus;
   int pid;
   char writemessages[10]={"Gowda"};
   char readmessage[10];
   returnstatus = pipe(pipefds);
   if (returnstatus == -1) {
      printf("Unable to create pipe\n");
      return 1;
   }
   pid = fork();
   
   // Child process
   if (pid == 0) 
{
      read(pipefds[0], readmessage, sizeof(readmessage));
      printf("Child Process - Reading from pipe – Message  is %s\n", readmessage);
   } else 
{ //Parent process
      printf("Parent Process - Writing to pipe - Message 1 is %s\n", writemessages);
      write(pipefds[1], writemessages, sizeof(writemessages));
      
   }
   return 0;
}
