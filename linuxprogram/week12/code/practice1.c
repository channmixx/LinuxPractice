#include "my.h"
int main()
{
	pid_t a,b,c;
	int r_num;
	int pipe1[2];
	int pipe2[2];
	char buf[4096];
	memset(buf,0,sizeof(buf));
	
	if((pipe(pipe1)<0)||(pipe(pipe2)<0))
	{
		perror("pipe fail\n");
		return -1;
		
	}
	
	a=fork();
	
	
	if(a<0)
	{
		perror("fork a fail\n");
		return -1;
	}
	else if(a==0)
	{
		sleep(5);
		close(pipe2[1]);
		if((r_num=read(pipe2[0],buf,100))>0)
			printf("child a read from pipe2:%s,total=%d\n",buf,r_num);
		close(pipe2[0]);
		exit(0);
	
	}
	else
	{
		b=fork();
		if(b<0)
		{
			perror("fork b fail\n");
		}
		else if(b==0)
		{
			sleep(2);
			close(pipe1[1]);
			if((r_num=read(pipe1[0],buf,100))>0)
				printf("child b read from pipe1:%s,total=%d\n",buf,r_num);
			close(pipe1[0]);
			
			close(pipe2[0]);
			if(write(pipe2[1],"67890",5)!=-1)
				printf("child b write pipe2 ok\n");
			close(pipe2[1]);
				
			
			exit(0);
		}
		else
		{
			c=fork();
			if(c<0)
			{
				perror("fork c fail\n");
			}
			else if(c==0)
			{
				close(pipe1[0]);
				if(write(pipe1[1],"12345",5)!=-1)
					printf("child c write pipe1 ok\n");
				close(pipe1[1]);
				return 0;
			}
			else
			{
				printf("parent pid=%d",getpid());
				
			}
		}
	}
	
}
