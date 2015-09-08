#函数stat、fstat、fstatat和lstat

'''
#include <sys/stat.h>
int stat(const char *restrict pathname, struct stat *restrict buf);
int fstat(int fd, struct stat *buf);
int lstat(cont char *restrict pathname, struct stat *restrict buf);
int fstatat(int fd, const char *restrict pathname, struct stat * restrict buf, int flags);
'''

stat函数返回与pathname命名文件有关的信息结构

fstat函数获得在描述符fd上打开文件的有关信息

lstat函数类似于stat，但是当命名的文件是一个符号链接时，lstat返回该符号链接的相关信息，而不是由该符号链接引用的文件的信息

fstatat函数为一个相对于当前打开目录（由fd参数指向）的路径名返回文件统计信息。falg参数控制着是否跟随一个符号链接。当AT_SYNMLINK_NOFOLLOW标志被设置时，fstatat不会跟随符号链接，而是返回符号链接本身的信息。否则，在默认情况下，返回的是符号链接所指向的实际文件的信息。如果fd参数的值是AT_FDCWD，并且pathname是一个相对路径名，fstatat会计算相对于当前目录的pathname参数。如果pathname是一个绝对路径，fd参数就会被忽略。
