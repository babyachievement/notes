#查询优化

查询优化器尝试选出一条语句所有查询计划中效率最高的。


PostgreSQl优化器执行一个“近似穷举搜索”（near-exhaustivesearch）。

rule based optimizer 和 cost based optimizer
In brief the rule-based method means that when executing a query the database must follow certain predefined rules and matter what data is stored in affected database tables. The cost-based method means the database must decide which query execution plan to choose using best guess approach that takes into account what data is stored in db.

http://docs.oracle.com/cd/B10500_01/server.920/a96533/optimops.htm
