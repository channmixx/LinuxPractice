#include "my.h"
#define PROMPT "do you wanna terminate the program?"
char *prompt=PROMPT;
void ctrl_c(signo)
{
	fprintf(stderr,prompt);
	
}


int main()
{
	struct sigaction act;
	act.sa_handler=ctrl_c;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	if(sigaction(SIGINT,&act,NULL)<0)
	{
		fprintf(stderr,"install signal action error:&s\n",strerror(errno));
		exit(1);
	}
	printf("process id is %d \n",getpid());
	while(1);
}
