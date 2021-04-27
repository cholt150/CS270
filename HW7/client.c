#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 4509
   
   
int main()
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;

    char buffer[1024] = {0};
    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
       
    // Convert IPv4
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

   
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    while(1) {
        fgets(buffer, 10, stdin);
        //printf("sending string %s to server\n",buffer);
        send(sock , buffer , strlen(buffer) , 0 );
        if (buffer[0] == 'q')
            return 0;
    }
    return 0;
}