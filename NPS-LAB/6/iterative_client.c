// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<unistd.h>
// #include<arpa/inet.h>
// #include<strings.h>
// #include<sys/socket.h>

// #define MAX 80
// #define PORT 15000

// void func(int sockfd)
// {
// 	char *buff = malloc(MAX);
// 	int n;
// 	for(;;)
// 	{
// 		n = 0;
// 		bzero(buff , sizeof(buff));
// 		printf("Enter the string to be sent to the server :\n");
// 		while((buff[n++] = getchar()) != '\n');
// 		write(sockfd , buff , sizeof(buff));
// 		bzero(buff , sizeof(buff));
// 		read(sockfd , buff , sizeof(buff));
// 		printf("From server : %s\n" , buff);
// 		if(strncmp(buff , "exit" , 4) == 0)
// 		{
// 			printf("Client exit...\n");
// 			break;
// 		}	
// 	}
// }

// int main()
// {
// 	int sockfd;
// 	struct sockaddr_in serv;
// 	sockfd = socket(AF_INET , SOCK_STREAM , 0);
// 	if(sockfd == -1)
// 	{
// 		printf("Socket connection failed...\n");
// 		exit(0);
// 	}
// 	printf("Socket successfully created...\n");
// 	bzero(&serv , sizeof(serv));
// 	serv.sin_family = AF_INET;
// 	serv.sin_port = htons(PORT);
// 	serv.sin_addr.s_addr = inet_addr("127.0.0.1");
// 	if(connect(sockfd , (struct sockaddr*)&serv , sizeof(serv)) != 0)
// 	{
// 		printf("Connection with server failed...\n");
// 		exit(0);
// 	}
// 	else
// 	{
// 		printf("Connected with server...\n");
// 		func(sockfd);
// 		close(sockfd);
// 	}
// 	return 0;
// }




//implementation

// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<unistd.h>
// #include<arpa/inet.h>
// #include<strings.h>
// #include<sys/socket.h>
// #define MAX 80
// #define PORT 15000
// void func(int sockfd)
// {
//     char *buff = malloc(MAX);
//     int n;
//     for(;;)
//     {
//         n = 0;
//         bzero(buff , sizeof(buff));
//         printf("Enter the string to be sent to the server :\n");
//         while((buff[n++] = getchar()) != '\n');
//         write(sockfd , buff , sizeof(buff));
//         bzero(buff , sizeof(buff));
//         read(sockfd , buff , sizeof(buff));
//         printf("From server : %s\n" , buff);
//         if(strncmp(buff , "exit" , 4) == 0)
//         {
//             printf("Client exit...\n");
//             break;
//         }   
//     }
// }
// int main()
// {
//     int sockfd;
//     struct sockaddr_in serv;
//     sockfd = socket(AF_INET , SOCK_STREAM , 0);
//     //bzero(&serv , sizeof(serv));
//     serv.sin_family = AF_INET;
//     serv.sin_port = htons(PORT);
//     serv.sin_addr.s_addr = inet_addr("127.0.0.1");
//     connect(sockfd , (struct sockaddr*)&serv , sizeof(serv));
//     func(sockfd);
//     close(sockfd);
//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<strings.h>
#include<sys/socket.h>
#define MAX 80
#define PORT 15000
void func(int sockfd)
{
    char *buff = malloc(MAX);
    int n;
    for(;;)
    {
        n = 0;
        printf("Enter the string to be sent to the server :\n");
        while((buff[n++] = getchar()) != '\n');
        send(sockfd , buff , sizeof(buff),0);
        recv(sockfd , buff , sizeof(buff),0);
        printf("From server : %s\n" , buff);
        if(strncmp(buff , "exit" , 4) == 0)
        {
            printf("Client exit...\n");
            break;
        }   
    }
}
int main()
{
    int sockfd;
    struct sockaddr_in serv;
    sockfd = socket(AF_INET , SOCK_STREAM , 0);
    serv.sin_family = AF_INET;
    serv.sin_port = htons(PORT);
    serv.sin_addr.s_addr = inet_addr("127.0.0.1");
    connect(sockfd , (struct sockaddr*)&serv , sizeof(serv));
    func(sockfd);
    close(sockfd);
    return 0;
}