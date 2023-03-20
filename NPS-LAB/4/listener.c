#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include<stdlib.h>
 
#define HELLO_PORT 12345
#define HELLO_GROUP "225.0.0.37" 
#define MSGBUFSIZE 25
 
main(int argc, char *argv[])
{
struct sockaddr_in addr;
int fd, nbytes,addrlen;
struct ip_mreq mreq;
char msgbuf[MSGBUFSIZE];
int yes=1;        	
fd=socket(AF_INET,SOCK_DGRAM,0);
setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(yes)) ;
addr.sin_family=AF_INET;
addr.sin_addr.s_addr=htonl(INADDR_ANY); 
addr.sin_port=htons(HELLO_PORT);
bind(fd,(struct sockaddr *) &addr,sizeof(addr));
mreq.imr_multiaddr.s_addr=inet_addr(HELLO_GROUP);
mreq.imr_interface.s_addr=htonl(INADDR_ANY);
setsockopt(fd,IPPROTO_IP,IP_ADD_MEMBERSHIP,&mreq,sizeof(mreq)) ;
	while (1) 
	{
	  	addrlen=sizeof(addr);
	  	recvfrom(fd,msgbuf,MSGBUFSIZE,0,(struct sockaddr *) &addr,&addrlen);
	  	puts(msgbuf);
	}
}

