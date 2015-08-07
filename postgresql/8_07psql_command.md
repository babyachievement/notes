#psql命令


查看当前事务id，每执行一次增加一
select txid_current();


select ctid, xmin, xmax, cmin, cmax from tablename;
