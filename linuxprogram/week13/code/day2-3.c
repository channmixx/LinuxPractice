#include "my.h"
static int sig_cnt[NSIG];   //统计数组
static int number=0;
int sigorder[128]={0};

#define MSG "#%d:receive signal %d\n"

void handler(int signo)
{
	sigorder[number++]=signo;  //来一个信号存一个
	
}

int main(int argc,char *argv[])
{
	int i=0;
	int k=0;
	sigset_t blockmask;
	sigset_t emptymask;
	sigset_t pendmask;
	struct sigaction sa;
	
	sigfillset(&blockmask);
	#ifdef USE_SIGACTION  //假如定义了
	sa.sa_handler=handler;
	sa.sa_mask=blockmask;
	sa.sa_flags=SA_RESTART;
	#endif
	printf("%s:PID is %d\n",argv[0],getpid());
	for(i=0;i<NSIG;i++)
	{
		if(i==SIGKILL||i==SIGSTOP)  //中止和暂停
		continue;
		#ifdef USE_SIGACTION
		if(sigation(i,&sa,NULL)!=0)
		#else
		if(signal(i,handler)==SIG_ERR)
		#endif
		{
			fprintf(stderr,"sigaction for signo(%d) failed (%s)\n",i,strerror(errno));
			return -1;
		}
		
	}
	int sleep_time=atoi(argv[1]);
	if(sigprocmask(SIG_SETMASK,&blockmask,NULL)==-1)
	{
		fprintf(stderr,"setmask to block all signol failed  (%s)\n",i,strerror(errno));
		return -2;
	}
	printf("i will sleep %ds\n",sleep_time);
	sleep(sleep_time);
	sigemptyset(&emptymask);
	if(sigprocmask(SIG_SETMASK,&emptymask,NULL)==-1)
	{
		fprintf(stderr,"setmask to release all signol failed  (%s)\n",i,strerror(errno));
		return -3;
	}
	for(i=0;i<number;i++) //休眠过程排队
	{
		if(sigorder[i]!=0)
		{
			printf("#%d : signo = %d\n",i,sigorder[i]);
		}
	}
	return 0;
	
}
