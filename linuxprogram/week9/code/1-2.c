#include <stdio.h>
#include <unistd.h>
int main()
{
	char *args[]={"/channmixx/bin/vim",NULL};
	printf("pid:%d\n",getpid());
	if(execve("/channmixx/bin/vim",args,NULL)<0)
	perror("用execve创建进程出错");
	return 1;
}
