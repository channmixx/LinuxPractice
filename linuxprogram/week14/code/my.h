#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <wait.h>
#include <errno.h>
#include <signal.h>
#include <assert.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>
#include <limits.h>
#include "err_exit.h"
#define check_error(return_val,msg){\
	if(return_val !=0){\
		fprintf(stderr,"%s:%s\n",msg,strerror(return_val));\
		exit(-1);\
	}\
}

