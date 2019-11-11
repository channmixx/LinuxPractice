#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int g=88;
int main()
{
	int v=99;
	pid_t pid;
	if(pid<0)
	{
		perror("vfork failed!\n");
		exit(-1);
	}
	else if(pid=0)
	{
		g++;
		v++;
		return 0;
	}
	printf("pid=%d,g=%d,v=%d\n",getpid(),g,v);
	return 0;
	
}


