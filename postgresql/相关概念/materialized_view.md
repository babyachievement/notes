#物化视图

维基的定义
>a materialized view is a database object that contains the results of a query.

物化视图现在也被称作"snapshot",可以理解为缓存查询的结果，可以看做提前计算的一种，可用来优化。


Oracle[edit]
Materialized views were implemented first by the Oracle Database: the Query rewrite feature was added from version 8i.[5]

Example syntax to create a materialized view in Oracle:

     CREATE MATERIALIZED VIEW MV_MY_VIEW
    REFRESH FAST START WITH SYSDATE
       NEXT SYSDATE + 1
         AS SELECT * FROM <table_name>;

PostgreSQL[edit]
In PostgreSQL, version 9.3 and newer natively support materialized views.[6] In version 9.3, a materialized view is not auto-refreshed, and is populated only at time of creation (unless WITH NO DATA is used). It may be refreshed later manually using REFRESH MATERIALIZED VIEW.[7] In version 9.4, the refresh may be concurrent with selects on the materialized view if CONCURRENTLY is used.[8]

Others[edit]
Materialized views are also supported in Sybase SQL Anywhere.[9] In IBM DB2, they are called "materialized query tables"; Microsoft SQL Server has a similar feature called "indexed views".[10] MySQL doesn't support materialized views natively, but workarounds can be implemented by using triggers or stored procedures [11] or by using the open-source application Flexviews.[12]

