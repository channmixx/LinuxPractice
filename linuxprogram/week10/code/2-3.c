#include "my.h"
int g=10;
int main()
{
	int s=20;
	static int k=30;
	pid_d pid;
	pid=fork();
	if(pid<0)
	{
		perror("fork fail\n");
		return -1;
	}
	else if(pid==0)
	{
		printf("child pid=%d:&g=%16p\n&k=%16p\n&s=%16p\n",getpid(),&g,&k,&s);
		g=100;
		s=200;
		k=300;
		sleep(2);
		printf("child after g=%d,s=%d,k=%d",g,s,k);
		_exit(0);
		//return 0;
	}else{
		//sleep(2);
		printf("parent pid=%d:&g=%16p\n&k=%16p\n&s=%16p\n",getpid(),&g,&k,&s);
		printf("parent after g=%d,s=%d,k=%d",g,s,k);
		return 0;
	}
}
