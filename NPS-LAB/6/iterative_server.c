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
		if(strncmp(buff , "exit" , 4) == 0)      
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
