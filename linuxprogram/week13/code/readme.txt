day1-1.c
绑定函数和信号
kill -x pid  发送中断信号 可用123  9（杀进程）

day1-2.c
修改ctrl+c后的显示字符串。

day1-3.c
不带参数运行的话，发出（记账）式信号
带参数运行，./day1-3  50
./1-11& 后台运行


day2-1.c  基于昨天day1-3.c的测试程序
./day2-1 pid signo times 
      (进程号 信号值  次数)
      
day2-2.c
绑定信号

day2-3.c
信号的顺序
1 屏蔽信号不相应
2 

gcc day2-3.c -o day2-3 -DUSE_SIGACTION
脚本test.sh
44号优先发送
4 5 8 7 11 硬件相关
用chmod +x test.sh更改脚本文件的权限

