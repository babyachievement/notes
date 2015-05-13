信号
=======================

信号传递的过程：
* 内核中针对每一个进程都有一个表来保存信号。
* 当内核需要将信号传递给某个进程时，就在该进程对应的表中写入信号，这样就生成了信号。
* 当该进程由用户态陷入内核态，再次切换到用户态之前，会查看表中的信号。如果有信号，进程就会首先执行信号对应的操作，此时叫做执行信号。
* 从生成信号到将信号传递给对应进程这段时间，信号处于等待状态。
* 我们可以编写代码，让进程阻塞(block)某些信号，也就是让这些信号始终处于等待的状态，直到进程取消阻塞(unblock)或者忽略信号。
