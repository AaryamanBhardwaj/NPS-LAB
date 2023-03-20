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
//         bzero(buff, MAX); 
  
//         // read the message from client and copy it in buffer 
//         read(sockfd, buff, sizeof(buff)); 
//         // print buffer which contains the client contents 
//         printf("From client: %s\t To client : ", buff); 
//         bzero(buff, MAX); 
//         n = 0; 
//         // copy server message in the buffer 
//         while ((buff[n++] = getchar()) != '\n') 
//             ; 
  
//         // and send that buffer to client 
//         write(sockfd, buff, sizeof(buff)); 
  
//         // if msg contains "Exit" then server exit and chat ended. 
//         if (strncmp("exit", buff, 4) == 0) { 
//             printf("Server Exit...\n"); 
//             break; 
//         } 
//     } 
// } 
  
// // Driver function 
// int main() 
// { 
//     int sockfd, connfd, len; 
//     struct sockaddr_in servaddr, cli; 
  
//     // socket create and verification 
//     sockfd = socket(AF_INET, SOCK_STREAM, 0); 
//     if (sockfd == -1) { 
//         printf("Socket creation failed...\n"); 
//         exit(0); 
//     } 
//     else
//         printf("Socket successfully created..\n"); 
//     bzero(&servaddr, sizeof(servaddr)); 
  
//     // assign IP, PORT 
//     servaddr.sin_family = AF_INET; 
//     servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
//     servaddr.sin_port = htons(PORT); 
  
//     // Binding newly created socket to given IP and verification 
//     if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
//         printf("socket bind failed...\n"); 
//         exit(0); 
//     } 
//     else
//         printf("Socket successfully binded..\n"); 
  
//     // Now server is ready to listen and verification 
//     if ((listen(sockfd, 5)) != 0) { 
//         printf("Listen failed...\n"); 
//         exit(0); 
//     } 
//     else
//         printf("Server listening..\n"); 
//     len = sizeof(cli); 
  
//     // Accept the data packet from client and verification 
//     connfd = accept(sockfd, (SA*)&cli, &len); 
//     if (connfd < 0) { 
//         printf("server acccept failed...\n"); 
//         exit(0); 
//     } 
//     else
//         printf("server acccept the client...\n"); 
  
//     // Function for chatting between client and server 
//     func(connfd); 
  
//     // After chatting close the socket 
//     close(sockfd); 
// } 


//my approach



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
