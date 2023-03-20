#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include <arpa/inet.h>
#include<strings.h>

int main()
{
	int sockfd;
	struct sockaddr_in serv , cli;
	sockfd = socket(AF_INET , SOCK_DGRAM , 0);
	serv.sin_family = AF_INET;
	serv.sin_port = htons(1600);
	serv.sin_addr.s_addr = INADDR_ANY;
	bind(sockfd , (struct sockaddr*)&serv , sizeof(serv));
	char *buff = malloc(1024);
	int len;
	for(;;)//rememeber iss loop mein "cli" hai parameters mein
	{
		len = sizeof(cli);
		recvfrom(sockfd , buff , sizeof(buff) , 0 , (struct sockaddr*)&cli , &len);
		sendto(sockfd , buff , sizeof(buff) , 0 , (struct sockaddr*)&cli , sizeof(cli));
	}
	return 0;
}