---------------homework1.c-----------
void print(char *str,int p):
参数入栈从右至左进行,p先进栈,str后进&p>&str
栈和堆是在程序运行时候动态分配的，局部变量均在栈上分配。 
栈是反向增长的，地址递减；malloc等分配的内存空间在堆空间。堆是正向增长的，地址递增。   
r,w变量在栈上(则&r>&w)，r,w所指内容在堆中(即r<w)

int main():
打印代码段中主函数和子函数的地址，编译时先编译的地址低，后编译的地址高main<print

//////////运行结果
variables address in main function: s1=0x4008a8  s2=0x4008a8 s3=0x7ffc909582a0 s4=0x7ffc90957f80 s5=0x4008a8 a=0x7ffc90957f60 b=0x7ffc90957f64 ["abcde"作为字符串常量存储在常量区 s1、s2、s5拥有相同的地址]

variables address in processcall:ns1=0x4008a8 s2=0x4008a8 s3=0x7ffc90957f40 s4=0x7ffc90957c20 s5=0x4008a8

a=0x7ffc90957bdc b=0x7ffc90957be0 c=0x7ffc90957be4 d=0x7ffc90957be8[a,b,c,d均在栈上，&a>&b>&c>&d地址反向增长]

str=0x7ffc90957bc8 q=0x400923 p=0x7ffc90957bc4 m=0x7ffc90957bec r=0x1cab420 w=0x1cab440 

main=0x4005d6 print=0x4006ce[打印代码段中主函数和子函数的地址，编译时先编译的地址低，后编译的地址高main<print]


-------------homework2.c--------------
要查看一个进程的虚拟地址空间的内存布局，需要设置阻塞。如果没有设置阻塞，当直接运行时，程序执行的速度非常快以至于来不及查看，所以需要设置阻塞。
1. gcc test.c -o test
2. ./test&  后面的&是让程序在后台运行
3. ps -u查看进程id 
4. cat /proc/进程id/maps 输出进程虚拟地址空间的布局

//////////运行结果
a=10,p=0x0xf0c010

