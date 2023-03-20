// #include<stdio.h>
// #include<stdlib.h>
// #include<unistd.h>
// #include<fcntl.h>
// #include<arpa/inet.h>
// #include<netinet/in.h>
// #include<sys/types.h>
// #include<sys/stat.h>
// #include <sys/socket.h>

// void str_cli(FILE *fp, int sockfd){
//     int cont, buffsize = 1024;
//     char *buffer = malloc(buffsize);

//     while(fgets(buffer, buffsize, fp) != NULL){
//         send(sockfd, buffer, buffsize, 0);
//         // cont = recv(sockfd, buffer, buffsize, 0);
//         // fputs(buffer, stdout);
//     }
// }

// int main(int argc, char *argv[])
// {
//     int create_socket, cont;
//     int buffsize = 1024;
//     char *buffer = malloc(buffsize);
//     char fname[256];
//     struct sockaddr_in address;

//     if((create_socket = socket(AF_INET, SOCK_STREAM, 0)) > 0)
//         printf("The socket is created\n");

//     address.sin_family = AF_INET;
//     address.sin_port = htons(15001);
//     //inet_pton(AF_INET, argv[1], &address.sin_addr);
//     address.sin_addr.s_addr=inet_addr("127.0.0.1");

//     if((connect(create_socket, (struct sockaddr*)&address, sizeof(address))) == 0)
//         printf("The connection was accepted\n");

//     str_cli(stdin, create_socket);
//     return close(create_socket);
// }


//my implementation

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<strings.h>
#include <sys/socket.h>
//#include<unistd.h>
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