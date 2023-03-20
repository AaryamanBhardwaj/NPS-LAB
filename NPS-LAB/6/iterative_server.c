// #include<stdio.h>
// #include<stdlib.h>
// #include<arpa/inet.h>
// #include<sys/socket.h>
// #include<string.h>
// #include<strings.h>
// #include<unistd.h>

// #define PORT 15000
// #define MAX 80

// void func(int sockfd)
// {
// 	char *buff = malloc(MAX);
// 	while(1)
// 	{
// 		bzero(buff , sizeof(buff));
// 		read(sockfd , buff , sizeof(buff));
// 		printf("From client : %s\n" , buff);
// 		write(sockfd , buff , sizeof(buff));
// 		if(strncmp(buff , "exit" , 4) == 0)      //isme exit type karke process exit karni hai not ctrl + c
// 		{
// 			break;
// 		}
// 	}
// }

// int main()
// {
// 	int sockfd , connfd , len;
// 	struct sockaddr_in serv , cli;
// 	if((sockfd = socket(AF_INET , SOCK_STREAM , 0)) < 0)
// 	{
// 		printf("Socket connection failed...\n");
// 		return 0;
// 	}
// 	printf("Socket connection successful...\n");
// 	bzero(&serv , sizeof(serv));
// 	serv.sin_family = AF_INET;
// 	serv.sin_port = htons(PORT);
// 	serv.sin_addr.s_addr = INADDR_ANY;
// 	if(bind(sockfd , (struct sockaddr*)&serv , sizeof(serv)) != 0)
// 	{
// 		printf("Bind failed...\n");
// 		return 0;
// 	}
// 	printf("Bind successful...\n");
// 	listen(sockfd , 3);
// 	while(1)
// 	{
// 		len = sizeof(cli);
// 		connfd = accept(sockfd , (struct sockaddr*)&cli , &len);
// 		if(connfd < 0)
// 		{
// 			printf("Connection failed...\n");
// 			return 0;
// 		}
// 		printf("Connection successful...\n");
// 		func(connfd);
// 	}
// 	close(sockfd);
// 	return 0;
// }



//my implementation

#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>
#include<strings.h>
#include<unistd.h>
#define PORT 15000
#define MAX 80
void func(int sockfd)
{
	char *buff = malloc(MAX);
	for(;;)
	{
		recv(sockfd , buff , sizeof(buff),0);
		send(sockfd , buff , sizeof(buff),0);
		if(strncmp(buff , "exit" , 4) == 0)      //isme exit type karke process exit karni hai not ctrl + c
		{
			break;
		}
	}
}

int main()
{
	int sockfd , connfd , len;
	struct sockaddr_in serv , cli;
	sockfd = socket(AF_INET , SOCK_STREAM , 0);
	serv.sin_family = AF_INET;
	serv.sin_port = htons(PORT);
	serv.sin_addr.s_addr = INADDR_ANY;
	bind(sockfd , (struct sockaddr*)&serv , sizeof(serv));
	listen(sockfd , 3);
	for(;;)
	{
		len = sizeof(cli);
		connfd = accept(sockfd , (struct sockaddr*)&cli , &len);
		func(connfd);
	}
	close(sockfd);
	return 0;
}