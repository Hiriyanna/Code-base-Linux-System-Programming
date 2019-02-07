#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
int main() 
{ 
char *args[]={"./exec",NULL};
//A null terminated array of character pointers 
        execvp(args[0],args); 
	// after this cal next statements not excecuting




	printf("Ending-----"); 
	      
	    return 0; 
} 
