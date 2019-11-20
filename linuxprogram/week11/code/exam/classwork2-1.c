#include "my.h"
int main()
{
	FILE *p=fopen("out.txt","w+");
	FILE *pp=fopen("out.txt","r");
	int pid1,pid2,i;
	char buff[512];
	if(((pid1=fork())&&(pid2=fork()))<0)
	{
		perror("fails to fork\n");
		return -1;
	}else if(pid1==0){
		fprintf(p,"%d:child1\n",getpid());
		for(i=0;i<10;i++)
		{
			fprintf(p,"%d ",i);
		}
		fprintf(p,"\n");
		fclose(p);
		
	}else if(pid2==0){
		fprintf(p,"%d:child2\n",getpid());
		for(i=0;i<10;i++)
		{
		fprintf(p,"%d ",i);
		}
		fprintf(p,"\n");
		fclose(p);
	}else{
		sleep(3);
		if (pp== NULL) {
			return -1;
		}
		while (!feof(pp))  {
		fgets(buff, sizeof(buff),pp);
		printf(" %s \n", buff);
		}
		fclose(pp);

		printf("parent %d finished\n",getpid());
	}
	exit(0);

}
