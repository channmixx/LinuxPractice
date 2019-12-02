#include "my.h"
void sigtoutine(int number)
{
	switch(number)
	{
		case 1:
		printf("get a signal SIGHUP\n");
		break;
		case 2:
		printf("get a signal SIGINT\n");
		break;
		case 3:
		printf("get a signal SIGQUIT\n");
		break;
	}
}

int main()
{
	printf("process id is %d\n",getpid());
	signal(SIGHUP,sigtoutine);
	signal(SIGINT,sigtoutine);
	signal(SIGQUIT,sigtoutine);
	while(1);
	
}
