#什么是Tid scan

通过Tid扫描表， TId是touple id的简写，由4字节的page number和2字节的页内的元组索引（tuple index）组成。tid 是ctid的类型。

tuple identifier (row identifier). This is the data type of the system column ctid. A tuple ID is a pair (block number, tuple index within block) that identifies the physical location of the row within its table.

So if you know the TID you can directly get the corresponding tuple.
