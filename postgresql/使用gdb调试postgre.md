#使用gdb调试postgres

编译的时候

./configure --enable-debug --enable-depend --enable-cassert --prefix=/usr/local/postgresql-9.4.4

或者修改
src/Makefile.Global

    CFLAGS = -Wall -Wmissing-prototypes -Wpointer-arith -Wdeclaration-after-statement -Wendif-labels -Wmissing-format-attribute -Wformat-security -fno-strict-aliasing -fwrapv -fexcess-precision=standard -g -O2

-02"选项删除，"-O2"是编译器的优化选项，如果打开了，代码的执行顺序会改变，使得追踪起代码来比较困难，所以要去除。当然这样的话，编译后的可执行文件会比较大，而且会比较慢，生产环境不太合适。大家需要理解这个操作仅仅是在学习的时候而设置的。


    $ ps -ef | grep post                                                                                                            [10:23:22]
    alvin    11242 10130  0 10:05 pts/27   00:00:00 /usr/local/postgresql-9.4.4/bin/postgres -D /home/alvin/pgdata
    alvin    11248 11242  0 10:05 ?        00:00:00 postgres: checkpointer process                                
    alvin    11249 11242  0 10:05 ?        00:00:00 postgres: writer process                                      
    alvin    11250 11242  0 10:05 ?        00:00:00 postgres: wal writer process                                  
    alvin    11251 11242  0 10:05 ?        00:00:00 postgres: autovacuum launcher process                         
    alvin    11252 11242  0 10:05 ?        00:00:00 postgres: stats collector process                             
    alvin    11284 10130  0 10:05 pts/27   00:00:00 /usr/local/postgresql-9.4.4/bin/psql -d demoDB
    alvin    11285 11242  0 10:05 ?        00:00:00 postgres: alvin demoDB [local] idle                           
    alvin    12311 11345  0 10:23 pts/28   00:00:00 grep --color=auto --exclude-dir=.bzr --exclude-dir=.cvs --exclude-dir=.git --exclude-dir=.hg --exclude-dir=.svn post


    alvin    11285 11242  0 10:05 ?        00:00:00 postgres: alvin demoDB [local] idle                           

从以上得到后端进程的进程ID

    $ sudo  gdb postgres 11285                                                                                                                                [10:37:19]
    [sudo] password for alvin: 
    GNU gdb (Ubuntu 7.7.1-0ubuntu5~14.04.2) 7.7.1
    Copyright (C) 2014 Free Software Foundation, Inc.
    License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
    This is free software: you are free to change and redistribute it.
    There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
    and "show warranty" for details.
    This GDB was configured as "x86_64-linux-gnu".
    Type "show configuration" for configuration details.
    For bug reporting instructions, please see:
    <http://www.gnu.org/software/gdb/bugs/>.
    Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.
    For help, type "help".
    Type "apropos word" to search for commands related to "word"...
    postgres: 没有那个文件或目录.
    Attaching to process 11285
    Reading symbols from /usr/local/postgresql-9.4.4/bin/postgres...done.
    Reading symbols from /lib/x86_64-linux-gnu/librt.so.1...Reading symbols from /usr/lib/debug//lib/x86_64-linux-gnu/librt-2.19.so...done.
    done.
    Loaded symbols for /lib/x86_64-linux-gnu/librt.so.1
    Reading symbols from /lib/x86_64-linux-gnu/libdl.so.2...Reading symbols from /usr/lib/debug//lib/x86_64-linux-gnu/libdl-2.19.so...done.
    done.
    Loaded symbols for /lib/x86_64-linux-gnu/libdl.so.2
    Reading symbols from /lib/x86_64-linux-gnu/libm.so.6...Reading symbols from /usr/lib/debug//lib/x86_64-linux-gnu/libm-2.19.so...done.
    done.
    Loaded symbols for /lib/x86_64-linux-gnu/libm.so.6
    Reading symbols from /lib/x86_64-linux-gnu/libc.so.6...Reading symbols from /usr/lib/debug//lib/x86_64-linux-gnu/libc-2.19.so...done.
    done.
    Loaded symbols for /lib/x86_64-linux-gnu/libc.so.6
    Reading symbols from /lib/x86_64-linux-gnu/libpthread.so.0...Reading symbols from /usr/lib/debug//lib/x86_64-linux-gnu/libpthread-2.19.so...done.
    done.
    [Thread debugging using libthread_db enabled]
    Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
    Loaded symbols for /lib/x86_64-linux-gnu/libpthread.so.0
    Reading symbols from /lib64/ld-linux-x86-64.so.2...Reading symbols from /usr/lib/debug//lib/x86_64-linux-gnu/ld-2.19.so...done.
    done.
    Loaded symbols for /lib64/ld-linux-x86-64.so.2
    Reading symbols from /lib/x86_64-linux-gnu/libnss_files.so.2...Reading symbols from /usr/lib/debug//lib/x86_64-linux-gnu/libnss_files-2.19.so...done.
    done.
    Loaded symbols for /lib/x86_64-linux-gnu/libnss_files.so.2
    0x00007f9c1d10438d in __libc_recv (fd=8, buf=buf@entry=0xc01880 <PqRecvBuffer>, n=n@entry=8192, flags=-1, flags@entry=0) at ../sysdeps/unix/sysv/linux/x86_64/recv.c:29
    29  ../sysdeps/unix/sysv/linux/x86_64/recv.c: 没有那个文件或目录.
    (gdb) 

    (gdb) b ExecResult
    Breakpoint 1, ExecResult (node=0xd13eb0) at nodeResult.c:75
    (gdb) 




>https://wiki.postgresql.org/wiki/Pgsrcstructure
