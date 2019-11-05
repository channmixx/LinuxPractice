#include "my.h"
#include <setjmp.h>
static jmp_buf g_stack_env;
static void fun1(int *a,int *b,int *c);
//static void fun2(void);

int main(void)
{
	int a=1;
	int b=1;
	int c=1;
	
	if(0==setjmp(g_stack_env))
	{
		printf("normal flow\n");
		printf("1:a=%db=%dc=%d\n",*a,*b,*c);
		fun1(&a,&b,&c);
	}else{
		printf("long jump flow\n");
		printf("2:a=%db=%dc=%d\n",*a,*b,*c);
	}
	return 0;
}
static void fun1(int *a,int *b,int *c)
{
	printf("enter fun1\n");
	++(*a);
	++(*b);
	++(*c);
	printf("fun1:a=%db=%dc=%d\n",*a,*b,*c);
	longjmp(g_stack_env,1);
	printf("leave fun1\n");
}
/*static void fun2()
{
	printf("enter fun2\n");
	longjmp(g_stack_env,1);
	printf("leave fun2\n");
}*/


