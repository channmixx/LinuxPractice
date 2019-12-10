#include "my.h"
#define NUM_THREADS 4
//printf("\n");
void hello(void *t)
{
	pthread_t my_tid;
	
	my_tid=pthread_self(); //
	printf("\t thread%d:my tid is %lx,hello world\n",t,my_tid);
	
}
int main()
{
	pthread_t tid;
	int rv,t;

	for(t=0;t<NUM_THREADS;t++)
	{
		
		rv=pthread_create(&tid,NULL,(void*(*)())hello,(void*)t);
		//强制类型转换
		if(rv!=0)
		{
		printf("thread create failed\n");
		return -1;
		}
		
		printf("create thread %lx\n",tid);
	}
	printf("bye~~~\n");
	pthread_exit(NULL);//这里不用join
}
