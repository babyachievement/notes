#mmap

mmap函数用于申请段内存空间。可以将这段内存空间作为进程间通信的共享内存，也可以将文件直接映射到其中。munmap函数则释放由mmap创建的这段内存空间。它们的定义如下：

    #include <sys/mman.h>
    void* map(void *start, size_t length, int prot, int flags, int fd, off_t offset);
    int munmap(void *start, size_t length);

start:这段内存地址的起始地址。设为NULL，系统则自动分配一个地址。
length：指定内存段的长度。
prot：设置内存段的访问权限。
* PROT_READ，内存段可读
* PROT_WRITE， 内存段可写
* PROT_EXEC,内存段可执行
* PROT_NONE,内存段不能被访问
flags：控制内存段内容被修改后程序的行为。
* MAP_SHARED:进程间共享这段内存
* MAP_PRIVATE:内存段为调用进程所私有
* MAP_ANONYMOUS:这段内存不是从文件映射而来的。
* MAP_FIXED:内存段必须位于start参数指定的地址处
* MAP_HUGETLB:按照"大内存页面"来分配内存空间

fd:被映射文件对应的文件描述符

