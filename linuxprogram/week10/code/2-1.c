#include "my.h"

static void __attribute__ ((constructor)) before_main()
{
	printf("constructor\n");
}
static void __attribute__ ((desstructor)) after_main()
{
	printf("desstructor\n");
}
static void callback1()
{
	printf("1:callback\n");
}
static void callback2()
{
	printf("2:callback\n");
}

int main()
{
	atexit(callback1);
	atexit(callback2);
	FILE *fp;
	char buf[]={"test data from full buffer"};
	if((fp=fopen("test.dat","w+"))==NULL)
	{
		perror("fail to fopen\n");
		return -1;
	}
	if(fputs(buf,fp)==EOF)
	{
		perror("fail to fputs\n");
		return -1;
	}
	printf("print:data from line buffer"); //不能加\n
	exit(0);
	//_exit(0);
	//return 0;
}
