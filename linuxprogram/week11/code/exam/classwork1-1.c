#include "my.h"
int main()
{
	int pid1,pid2,p1,s1,p2,s2;
	if(((pid1=fork())&&(pid2=fork()))<0)
	{
		perror("fails to fork\n");
		return -1;
	}else if(pid1==0){
		printf("%d:child1 is running now\n",getpid());
		//getchar();
		//while(1);
		printf("%d:child1 exit now\n",getpid());
		exit(120);
	}else if(pid2==0){
		printf("%d:child2 is running now\n",getpid());
		//getchar();
		//while(1);
		printf("%d:child2 exit now\n",getpid());
		exit(130);
	}else{
		//sleep(3);
		printf("%d:parent is running zombie now\n",getpid());
		p1=wait(&s1);
		p2=wait(&s2);
		if((WEXITSTATUS(&s1))==120)  //如果获取的退出码是120的话
		{
			printf("child1 %d\n",p1);
		}
		else
		{
		
		}
		/*while((p=waitpid(pid1,&s,WNOHANG))!=-1)
		{
			printf("%d:parent is exiting now\n",getpid());
			if(WIFEXITED(s))
			{ 
				printf("child %d is exiting now.exit code=%d	\n",p,WEXITSTATUS(s));
			}else if(WIFSIGNALED(s))
			{
			printf("child %d exit by signal.signal no=%d\n",p,WTERMSIG(s));
			}else{
				printf("not konw\n");
			}
		}*/
		
		printf("parent finished\n");
	}
	exit(0);
}
