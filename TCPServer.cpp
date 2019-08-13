#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errorno.h>
#define MYPORT 32554
#define MAX 100
#define BUFFSIZE 1024

int main(int argc, char* argv[])
{
	int sd,connFd;
	struct sockaddr_in servAddr,cliAddr;
	char buff[MAX];


	sd=socket(AF_INET,SOCK_STREAM,0);
	if(sd<0) {
		//error
		exit(0);
	}
      memset(&servAddr,0,sizeof(sockaddr_in));
      servAddr.sin_family=AF_INET;
      servAddr.sin_port=MYPORT;
      servAddr.sin_addr.s_addr=htonl(INADDR_ANY);
      int retBind=bin(sd,(struct sockaddr_in *)&servAddr,sizeof(struct sockaddr_in));
      if(retBind < 0) {
	      //error
	      exit(1);
      }
      listen(sd,5);
      while(1) {
	      printf("Server started \n");
	      connFd=accept(sd,(struct sockaddr_in *)&cliAddr,sizeof(struct sockaddr_in));
             
	      char *client=(char *)inet_ntop(AF_INET,&cliAddr.sin_addr,buff,sizeof(buff));
