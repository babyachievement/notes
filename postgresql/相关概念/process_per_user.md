#process per user

在PostgreSQL建立连接阶段，PostgreSQL使用process per user的方式与客户端建立连接，由于不知道会有多少连接，PostgreSQL有一个master进程负责生产子进程负责与客户端程序建立连接。

    PostgreSQL is implemented using a simple "process per user" client/server model. In this model there is one client process connected to exactly one server process. As we do not know ahead of time how many connections will be made, we have to use a master process that spawns a new server process every time a connection is requested. This master process is called postgres and listens at a specified TCP/IP port for incoming connections. Whenever a request for a connection is detected the postgres process spawns a new server process. The server tasks communicate with each other using semaphores and shared memory to ensure data integrity throughout concurrent data access.
