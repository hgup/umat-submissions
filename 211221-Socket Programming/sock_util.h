#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
int createTCPIpv4Socket(void);
struct sockaddr_in* createIPv4Address(char*,int);
