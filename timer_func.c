#include <stdio.h> 
#include <time.h> 
int main()
{
	 clock_t t, t2; 
	 t = clock(); 
	 fun(); 
         t2 = clock(); 
         double time_taken = ((double)t2-t)/CLOCKS_PER_SEC; // in seconds 
			   
	 printf("fun() took %f seconds to execute \n", time_taken); 
	 return 0; 
} 
void fun() 
{ 
int i;
	    printf(" Hai gowda \n"); 
	    printf("hai \n"); 
		    for(i=0; i<1080; i++) 
			        { 
			//	printf("Hiriyanna gowda\n");	        
					       
				 } 
            printf("fun() ends \n"); 
} 
  
