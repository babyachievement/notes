#关于postgres.bki

.bki文件是用来初始化template模板数据库的。
postgres.bki文件是在在编译的过程中，由/src/backend/catalog下的genbki.pl读取/src/include/catalog下的以.h结尾的系统表定义文件创建，在安装目录里，通常放在share下。

[!include/catalog下的.h文件](include_catalog_h.png)

在pg__*.h这样的文件中定义了相应的系统表的数据结构，同时还包括：

* 定义CATALOG宏，用于以统一的模式定义系统表的结构以及用以描述系统表的数据结构，如系统表pg__class的定义通过CATALOG(pg__class, 1259)来实现。
* 通过宏DATA(x)和DESR(x)来定义insert操作，用于定义系统表中的初始数据


模板数据库template1是通过运行在bootstrap模式下的postgres程序读取postgres.bki文件创建的，这种模式允许在不存在系统表表的零初始条件下执行数据库函数。


