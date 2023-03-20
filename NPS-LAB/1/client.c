// #include<unistd.h>
// #include <netdb.h> 
// #include <stdio.h> 
// #include <stdlib.h> 
//  #include<arpa/inet.h>
// #include <string.h> 
// #include <netdb.h> 
// #include <stdio.h> 
// #include <stdlib.h> 
// #include <string.h> 
// #include <sys/socket.h> 
// #define MAX 80 
// #define PORT 8080 
// #define SA struct sockaddr 
// void func(int sockfd) 
// { 
//     char buff[MAX]; 
//     int n; 
//     for (;;) { 
//         bzero(buff, sizeof(buff)); 
//         printf("Enter the string : "); 
//         n = 0; 
//         while ((buff[n++] = getchar()) != '\n') 
//             ; 
//         write(sockfd, buff, sizeof(buff)); 
//         bzero(buff, sizeof(buff)); 
//         read(sockfd, buff, sizeof(buff)); 
//         printf("From Server : %s", buff); 
//         if ((strncmp(buff, "exit", 4)) == 0) { 
//             printf("Client Exit...\n"); 
//             break; 
//         } 
//     } 
// } 
  
// int main() 
// { 
//     int sockfd, connfd; 
//     struct sockaddr_in servaddr, cli; 
  
//     // socket create and varification 
//     sockfd = socket(AF_INET, SOCK_STREAM, 0); 
//     if (sockfd == -1) { 
//         printf("socket creation failed...\n"); 
//         exit(0); 
//     } 
//     else
//         printf("Socket successfully created..\n"); 
//     bzero(&servaddr, sizeof(servaddr)); 
  
//     // assign IP, PORT 
//     servaddr.sin_family = AF_INET; 
//     servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
//     servaddr.sin_port = htons(PORT); 
  
//     // connect the client socket to server socket 
//     if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
//         printf("connection with the server failed...\n"); 
//         exit(0); 
//     } 
//     else
//         printf("connected to the server..\n"); 
  
//     // function for chat 
//     func(sockfd); 
  
//     // close the socket 
//     close(sockfd); 
// } 


//my approach
//send()-TCP
//sendto()-UDP

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
    close(sockfd);//this will always come after func
}
