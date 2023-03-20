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
        printf("to server:\n");
        while((buff[n++]=getchar())!='\n');  //dont forget \n
        send(sockfd,buff,sizeof(buff),0);
        bzero(buff,sizeof(buff));//does not work correctly without bzero
        recv(sockfd,buff,sizeof(buff),0);
        printf("\nfrom server:%s",buff);
        if(strncmp(buff,"exit",4)==0){
            break;
        }

    }
}
int main(){
    int sockfd;
    struct sockaddr_in servaddr;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(8080);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    func(sockfd);
    close(sockfd);
}
