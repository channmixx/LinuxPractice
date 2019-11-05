#include "my.h"
int main()
{
	int ret;
	char *arg[]={"./test2","123","abc","hello","ncu","edu",NULL};
	printf("call1:pid=%d,ppid=%d\n",getpid(),getppid());
	execvp("test2",arg);
	printf("after calling! ret=%d\n",ret);
	return 0;
}
