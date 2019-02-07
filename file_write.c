#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
FILE  *fp;
char ch;

fp= fopen("gowda.txt","w");
if(fp==NULL)
{
	printf("file not able to open\n");
}
else
{
	fprintf(fp,"He is a nice boy, got a big oppertunity use it" );

	fclose(fp);
}
return 0;


}
