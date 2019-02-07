#include<stdio.h>
#include<stdlib.h>
//#include <conio.h>
#include<fcntl.h>
int main()
{
FILE  *fp;
char ch;

fp= fopen("gowda.txt","r");
if(fp== NULL)
{
	printf("file not able to open\n");
}
else
{
	while(!feof(fp))
	{
	        ch=fgetc(fp);
		printf("%c",ch);
	}
	fclose(fp);
}
//getch();
return 0;


}
