#include<unistd.h>
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
 #include<arpa/inet.h>
#include <string.h> 
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
void func(int sockfd){
    char buff[80];
    for(;;){
         int n=0;
        printf("from client:\n");
        recv(sockfd,buff,sizeof(buff),0);
        printf("%s",buff);
        bzero(buff,sizeof(buff));//apply bzero wherever necesssary
        printf("\nto client:%s",buff);
        while((buff[n++]=getchar())!='\n');
        send(sockfd,buff,sizeof(buff),0);
        bzero(buff,sizeof(buff));
        if(strncmp(buff,"exit",4)==0){
            break;
        }
    }
}
int main(){
    int sockfd,connfd;
    struct sockaddr_in servaddr,cliaddr;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(8080);
    servaddr.sin_addr.s_addr=INADDR_ANY;
    bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    listen(sockfd,5);
    u_int len=sizeof(cliaddr);
    connfd=accept(sockfd,(struct sockaddr*)&cliaddr,&len);
    func(connfd);
    close(sockfd);
}
