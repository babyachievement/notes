#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

int main(int argc, char *argv[])
{
    if( argc <= 2  )
    {
        printf("usage: %s ip_address port_number\n", basename(argv[0]));
        return 1;
    }

    const char * ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = port;
    inet_pton(AF_INET, ip, &server_address.sin_addr);

    int socket_fd = socket(PF_INET, SOCK_STREAM, 0);
    int ret;

    ret = bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address));
    if( ret < 0  )
    {
         perror("bind");
         exit(1);
    }

    ret = listen(socket_fd, 5);
    if ( ret < 0  )
    {
        perror("listen");
        exit(1);
    }

    struct sockaddr_in client;
    int client_length = sizeof(client);
    int connfd =  accept(socket_fd,(struct sockaddr *)&client, &client_length );
    if ( connfd < 0  )
    {
        perror("accept");
        exit(1);
    }

    close(STDOUT_FILENO);
    dup(connfd);
    printf("abcd\n");

    close(socket_fd);
    return 0;
}
