#ext2

boot block :1k

block group:块组
* super block
* GDT :块组描述符
* Block Bitmap:bit位描述块组中每个块的使用情况
* inode Table 
* Data Blocks

超级块(super block):描述整个分区的文件系统信息，如:块大小、文件系统版本号、上次mount时间等。超级块在每个块组的开头都有一个拷贝。
inode:存放文件的属性

