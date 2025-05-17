# Stack Trace

StackTrace使用gdb命令获取程序崩溃的堆栈，提高排查问题的效率

## 基本原理

通过注册信号处理函数，在程序发生崩溃时，运行gdb命令，抓取当前进程运行堆栈

## 使用方式

将stacktrace.cpp编译到项目中即可,参考demo示例

## 其他

https://github.com/bombela/backward-cpp
