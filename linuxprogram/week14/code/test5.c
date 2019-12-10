#include "my.h"
int fun(void *d)
{
	printf("tid=%p\n",pthread_self());
}

int main()
{
	pthread_t tid;
	int ret;
	ret=thread_create(&tid,NULL,(void*(*))fun,NULL);
	pthread_join(tid,NULL);
	ret=thread_create(&tid,NULL,(void*(*))fun,NULL);
	pthread_join(tid,NULL);
	return 0;
}
