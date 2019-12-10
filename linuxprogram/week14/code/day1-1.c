#include "my.h"
//printf("\n");
void *threadfun(void *arg)
{
	printf("thread pid is %d\n",getpid());
}

int main()
{
	pthread_t tidp;
	int error;
	error=pthread_create(&tidp,NULL,threadfun,NULL);
	if(error!=0)
	{
		printf("thread create failed\n");
		return -1;
	}
	printf("main thread is end! pid=%d  tid=%lx \n",getpid(),tidp);
	pthread_join(tidp,NULL);  //父线程等待子线程的结束
	return 0;
}
