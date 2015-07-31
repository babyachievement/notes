#postgresql中的pg_log pg_xlog和pg_clog文件夹

##pg_log
 
$PGDATA/pg_log is the default location for the database activity logs, which include error messages, query logging, and startup/shutdown messages.  This is where you should first look for information when PostgreSQL won't start.  Many Linux distributions and other packaging systems relocate this log directory to somewhere like /var/log/postgresql.
 
You can freely delete, rename, compress, and move files in pg_log without penalty, as long as the postgres user still has rights to write to the directory. If pg_log becomes bloated with many large files, you probably need to decrease the number of things you're logging by changing the settings in postgresql.conf.
 
##pg_xlog 
 
$PGDATA/pg_xlog is the PostgreSQL transaction log.  This set of binary log files, with names like '00000001000000000000008E', contain images of the data from recent transactions.  These logs are also used for binary replication.
If replication, archiving, or PITR(定时回滚恢复) is failing, this directory can become bloated with gigabytes of logs the database server is saving for when archiving resumes. This can cause you to run out of disk space.
 
Unlike pg_log, you may not freely delete, move, or compress files in this directory.  You may not even move the directory without symlinking it back to its original location.  Deleting pg_xlog files may result in irrecoverable database corruption.
 
If you find yourself in a situation where you've got 100GB of files in pg_xlog and the database won't start, and you've already disabled archiving/replication and tried clearing disk space every other way, then please take two steps:
 
1. Move files from pg_xlog to a backup disk or shared network drive, don't delete them, and
2. Move only a few of the oldest files, enough to allow PostgreSQL to start again.
 
##pg_clog
 
$PGDATA/pg_clog contains a log of transaction metadata.   This log tells PostgreSQL which transactions completed and which did not.  The clog is small and never has any reason to become bloated, so you should never have any reason to touch it.
 
Should you ever delete files from pg_clog, you might as well delete the entire database directory.  There is no recovery from a missing clog.
 
Note that this means, if you back up the files in a $PGDATA directory, you should make sure to include the pg_clog and pg_xlog as well, or you may find that your backup is not usable.
