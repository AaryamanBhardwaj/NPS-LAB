#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<strings.h>
#include<string.h>
#define MAX 1024

int main(int argc , char *argv[])
{
	int sockfd;
	struct sockaddr_in serv;
	sockfd = socket(AF_INET , SOCK_DGRAM , 0);
	printf("Socket was created...\n");
	serv.sin_family = AF_INET;
	serv.sin_port = htons(1600);
	serv.sin_addr.s_addr = inet_addr("127.0.0.1");
	char * buff = malloc(MAX);
	int len;
	for(;;)
	{
		int n=0;
		while((buff[n++]=getchar())!='\n');
		len = sizeof(serv);
		sendto(sockfd , buff , sizeof(buff) , 0 , (struct sockaddr*) &serv , sizeof(serv));
		recvfrom(sockfd , buff , sizeof(buff) , 0 , (struct sockaddr*)&serv , &len);
		printf("From server : %s\n" , buff);
	}
	return 0;
}