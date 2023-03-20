#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <arpa/inet.h>
void str_echo(int connfd)			
{
	int n;
	int bufsize = 1024;
	char *buffer = malloc(bufsize);
	for(;;)
	{
		recv(connfd, buffer, bufsize, 0);
		send(connfd,buffer,bufsize,0);
	}
}
int main()
{
	int sockfd, connfd, addrlen, pid, addrlen3;
	struct sockaddr_in address, cli_address;		
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;		
	address.sin_port = htons(15001);
	bind(sockfd, (struct sockaddr *)&address, sizeof(address));
	listen(sockfd, 3);			
	for(;;)				
	{
		addrlen = sizeof(struct sockaddr_in);
		connfd = accept(sockfd, (struct sockaddr *)&cli_address, &addrlen);
		if ((pid = fork()) == 0)
		{
			printf("inside child\n");
			close(sockfd);		
			str_echo(connfd);		
		}
	}
	return 0 ;
}
