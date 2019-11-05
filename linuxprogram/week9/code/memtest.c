#include "my.h"
#include <string.h>
static void mem_leak1()
{
	char *p=malloc(1);
}
static void mem_leak2()
{
	FILE *fp=fopen("test.txt","w");
}
static void mem_overrun1()
{
	char *p=malloc(1);
	*(short *)p=2;
	free(p);
}
static void mem_overrun2()
{
	char array[5];
	strcpy(array,"hello");
}
static void mem_double_free()
{
	char *p=malloc(1);
	free(p);
	free(p);
}
static void mem_free_wild_pointer()
{
	char *p;
	free(p);
}
int main()
{
	mem_leak1();
}

