#include"sock_util.h"

//This function creates a socket of IPV4 family and TCP socket type. The value that this function returns is the file descriptor to the socket

int createTCPIpv4Socket()
{
 int socketFD;
 return socketFD = socket(AF_INET, SOCK_STREAM, 0);
}

//This function creates an IPV4 address by allocating memory for the sockaddr_ in structure and returns the pointer to that address

struct sockaddr_in* createIPv4Address(char *ip, int port)
{
 struct sockaddr_in *address = malloc(sizeof(struct sockaddr_in));
 address->sin_family = AF_INET;
 address->sin_port = htons(port);
 if (strlen(ip) == 0)
     address->sin_addr.s_addr = INADDR_ANY;
 else
     inet_pton(AF_INET, ip, &address->sin_addr);
 printf("In create address\n");
 return address;
}
