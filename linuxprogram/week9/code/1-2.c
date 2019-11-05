#include <stdio.h>
#include <unistd.h>
int main()
{
	char *args[]={"/user/bin/vim",NULL};
	printf("pid:%d\n",getpid());
	if(execve("/user/bin/vim",args,NULL)<0)
	perror("用execve创建进程出错");
	return 1;
}
