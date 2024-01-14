#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define XG(a,b,c) a<b?c:a>b?b:a
#define CHX(a,b,c) c = a; a = b; b = c
#define j "neighbour"

int main() 
{
    int s,n_s;
    struct sockaddr_in a={AF_INET,INADDR_ANY,htons(8080)};
    if((s=socket(AF_INET,SOCK_STREAM,0))<0) exit(EXIT_FAILURE);
    if(bind(s,(struct sockaddr*)&a,sizeof(a))<0) exit(EXIT_FAILURE);
    if(listen(s,3)<0) exit(EXIT_FAILURE);
    if((n_s=accept(s,NULL,NULL))<0) exit(EXIT_FAILURE);
    char b[1024]={0};
    read(n_s,b,sizeof(b));
    printf("%s\n",b);
    const char*r="gd normal";
    send(n_s,r,strlen(r), 0);
    printf(j);
    close(n_s);
    close(s);
    return 0;
}