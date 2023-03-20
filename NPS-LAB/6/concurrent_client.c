// #include <sys/socket.h>
// #include <sys/types.h>
// #include <netinet/in.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <arpa/inet.h>

// void str_cli(FILE *fp, int sockfd)
// {
// 	int bufsize = 1024;
// 	char *buffer = malloc(bufsize);

// 	while (fgets(buffer, bufsize, fp) != NULL)
// 	{
// 		send(sockfd, buffer, sizeof(buffer), 0);  
// 		if (recv(sockfd, buffer, bufsize, 0) > 0) 
// 	    		fputs(buffer, stdout);
// 	}
	
// 	printf("\nEOF\n");
	
// 	free(buffer);
// }


// int main(int argc,char *argv[])
// {
// 	int sockfd;
// 	struct sockaddr_in address;
	
// 	if ((sockfd = socket(AF_INET,SOCK_STREAM,0)) > 0)
// 		printf("The socket was created\n");
		
// 	address.sin_family = AF_INET;
// 	address.sin_port = htons(15001);			
// 	inet_pton(AF_INET, argv[1], &address.sin_addr);	
	
// 	if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) == 0)
// 		printf("The connection was accepted with the server %s...\n",argv[1]);
// 	else
// 		printf("Error in connect\n");			
		
// 	str_cli(stdin, sockfd);				

// 	return close(sockfd);
// }



//my implementiaon

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
void str_cli(int sockfd)
{
    int bufsize = 1024;
    char buffer[80];
    for(;;)
    {
        int n=0;
        while((buffer[n++]=getchar())!='\n');
        send(sockfd, buffer, sizeof(buffer), 0);  
        recv(sockfd, buffer, bufsize, 0) ;
        printf("%s",buffer);
    }
}
int main(int argc,char *argv[])
{
    int sockfd;
    struct sockaddr_in address;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    address.sin_family = AF_INET;
    address.sin_port = htons(15001);            
    address.sin_addr.s_addr= inet_addr("127.0.0.1"); 
    connect(sockfd, (struct sockaddr *)&address, sizeof(address));         
    str_cli(sockfd);             
    return close(sockfd);
}
