#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<strings.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include<stdlib.h>
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr
void func(int sockfd){
    char buff[80];
    for(;;){
        int n=0;
        while((buff[n++]=getchar())!='\n');
        send(sockfd,&buff,sizeof(buff),0);
        recv(sockfd,&buff,sizeof(buff),0);
        printf("%s\n",buff);
    }
}
int main(){
    int sockfd;
    struct sockaddr_in servaddr;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(12345);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    connect(sockfd,(SA*)&servaddr,sizeof(servaddr));
    func(sockfd);
    close(sockfd);
}
