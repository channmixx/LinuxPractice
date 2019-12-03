#include "my.h"
int main(int argc,char *argv[])
{
	
	printf("pid=%d,signo=%d,time=%d\n",pid,signo,times);
	for(i=0;i<times;i++)
	{
		if(kill(pid,signo)==-1)
		{
			fprintf(stderr,"send signo(%d) to pid(%d) failed,reason(%s)\n",signo,pid,strerror(errno));
			return -3;
		}
	}
	fprintf(stdout,"done\n");
	return 0;
}
