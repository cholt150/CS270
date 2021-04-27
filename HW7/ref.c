#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 4509
int main()
{
    int server_fd, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[10] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    listen(server_fd, 3);

    int s1 = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    //int s2 = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    puts("Simple Echo Server using sockets. Type q to quit");
    while(1) {
        valread = read( s1 , buffer, 10);
        if(valread)
            printf("%s\n",buffer );
        if (buffer[0] == 'q')
            return 0;
    }

    return 0;
}
