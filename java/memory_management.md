#java内存管理

##手动释放和自动管理

###手动释放容易导致的问题
1. dangling reference(野指针)
2. space leak(内存泄露)

导致野指针的原因：未初始化的指针，多个指针指向一个地址
导致内存泄露的原因：代码bug，没有完全释放，从而导致系统内存资源耗尽

###垃圾自动收集的好处
不会引起野指针（无效引用），因为只要有一个引用指向那个地址，那块内存就不能被释放

同样，自动回收机制也能解决内存泄露的问题


##垃圾回收的概念

垃圾回收的任务：
* 分配内存
* 被引用的对象保持在内存中
* 回收被引用但不会再被执行的代码使用的对象

对象存活和对象死亡
回收内存的机制

分配内存时如何找到可用内存，如何避免内存碎片

##垃圾回收器的特点
安全并且能够被理解，


##Genneration Collection
内存分代
weak generational hypothesis
* Most allocated objects are not referenced(consideraed live) for long, that is, they die young
* Few references from older to younger objects exist.

年轻代的内存区通常较小，收集的频率较高并且收集速度比较快，是因为通常young generation space更小并且更有可能包含很多不再引用的对象

存活过相当数量的年轻代的收集器收集周期的年轻代的对象将最终被升级到老年代，old generatin space通常更大，所占的空间增长更慢，老年代的收集器收集的频率更低，但耗费的时间相对要长。

##Garbage collectors in J2SE 5.0 HotSpot JVM
Java HotSpot 虚拟机包含4个收集器.

###HotSpot Generation
HotSport虚拟机将内存划分为3代，young generation， old generation， permanent generation。

Young generation包含一个Eden 区和两个survivor区，
The young generation consists of an area called Eden plus two smaller survivor spaces, as shown in Figure 2.
Most objects are initially allocated in Eden. (As mentioned, a few large objects may be allocated directly in the
old generation.) The survivor spaces hold objects that have survived at least one young generation collection
and have thus been given additional chances to die before being considered “old enough” to be promoted to the
old generation. At any given time, one of the survivor spaces (labeled From in the figure) holds such objects,
while the other is empty and remains unused until the next collection.


The young generation collector is a copying collector. The young generation is divided into 3 spaces: eden-space, to-space, and from-space. Allocations are done from eden-space and from-space. When those are full a young generation is collection is done. The expectation is that most of the objects are garbage and any surviving objects can be copied to to-space. If there are more surviving objects than can fit into to-space, the remaining objects are copied into the tenured generation. There is an option to collect the young generation in parallel.
 
 The tenured generation is collected with a mark-sweep-compact collection. There is an option to collect the tenured generation concurrently.
