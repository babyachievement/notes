#VACUUM

数据库总是不断地在执行删除，更新等操作。良好的空间管理非常重要，能够对性能带来大幅提高。在postgresql中用于维护数据库磁盘空间的工具是VACUUM，其重要的作用是删除那些已经标示为删除的数据并释放空间。
VACUUM语法结构：


VACUUM [ FULL ] [ FREEZE ] [ VERBOSE ] [ table ]
VACUUM [ FULL ] [ FREEZE ] [ VERBOSE ] ANALYZE [ table [ (column [, ...] ) ] ]
 

postgresql中执行delete操作后，表中的记录只是被标示为删除状态，并没有释放空间，在以后的update或insert操作中该部分的空间是不能够被重用的。经过vacuum清理后，空间才能得到释放。可惜的是vacuum工具不能够对相应的索引进行清理，唯一的办法就是手动去重建相应索引(令人非常不爽，而高兴的是在9.0之后有所改进)。

##Full Vacuum

full vacuum与单纯的vacuum还是有很大的区别的。vacuum只是将删除状态的空间释放掉，转换到能够重新使用的状态，但是对于系统来说该数据块的空闲空间并没有反应到系统的元数据中。类似oracle中高水位标记并没有下降。Full vacuum将会使空间释放的信息表现在系统级别，其实质是将当前删除记录后面的数据进行移动，使得整体的记录连贯起来，降低了“高水位标记”。

##Vacuum analyze

analyze的功能是更新统计信息，使得优化器能够选择更好的方案执行sql。oracle中同样也有analyze，作用也相同，目前更多的使用的是dbms_stats包。统计信息收集和更新对于系统性能来说非常重要，与oracle维护类似，通常可以通过采用手动或者定制任务的方式。也有不同，oracle在进行imp后自动的对相应数据对象进行统计信息的收集和更新，而postgresql的恢复过程还没有集成到里面，需要手动去执行。
