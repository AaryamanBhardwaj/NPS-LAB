
// //sneha mams approach
// #include<stdio.h>
// #include<sys/types.h>
// #include<sys/socket.h>
// #include<netinet/in.h>
// #include<unistd.h>
// #include<arpa/inet.h>
// #include<stdlib.h>
// void str_echo(FILE *fp,int sockfd)
// {
// 	int n=1024,cont;
// 	char *buf=malloc(n);
// 	while(fgets(buf,n,fp)!=NULL)
// 	{
// 		//printf("\nEnter the string:\n");
// 		//scanf("%s",buf);
// 		send(sockfd,buf,n,0);
	
// 	//	printf("%s",buf);
// 		if((n=recv(sockfd,buf,n,0))>0)
// 			fputs(buf,stdout);  // dont forget stdout
// 	}
// 	printf("\nEOF\n");
// }
// int main(int argc,char *argv[])
// {
// 	int sockfd;
// 	struct sockaddr_in servaddr;
// 	printf("%s\n",argv[1]);
// 	if(sockfd=socket(AF_INET,SOCK_STREAM,0))
// 		printf("\nSocket created\n");
// 	servaddr.sin_family=AF_INET;
// 	servaddr.sin_port=htons(15001);
// 	//inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
// 	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
// 	connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	
// 	str_echo(stdin,sockfd);
// 	close(sockfd);
// }


// my code

// #include<stdio.h>
// #include<unistd.h>
// #include<sys/types.h>
// #include<strings.h>
// #include <sys/socket.h>
// #include <arpa/inet.h>
// #include<stdlib.h>
// #define MAX 80 
// #define PORT 8080 
// #define SA struct sockaddr
// void func(FILE *fp,int sockfd){
//     char buff[80];
//     //while(fgets(buff,sizeof(buff),fp)!=NULL){
//     while(fgets(buff,sizeof(buff),fp)!=NULL){
//         send(sockfd,&buff,sizeof(buff),0);
//         if(recv(sockfd,&buff,sizeof(buff),0)>0)
//         fputs(buff,stdout);

//     }
// }
// int main(){
//     int sockfd;
//     struct sockaddr_in servaddr;
//     sockfd=socket(AF_INET,SOCK_STREAM,0);
//     servaddr.sin_family=AF_INET;
//     servaddr.sin_port=htons(12345);
//     servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
//     connect(sockfd,(SA*)&servaddr,sizeof(servaddr));
//     func(stdin,sockfd);
//     close(sockfd);
// }




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
    func(sockfd);//take care that in program of every client we pass sockffd not connfd
    close(sockfd);
}