#include"sock_util.h"
#include<stdbool.h>
#include<pthread.h>
#include<unistd.h>
#include<stdint.h>
#include<string.h>
#define port 2000 
//This function receives the data from the client and prints it on a differnt thread
void listenAndPrint(int socketFD)
{
 char buffer[1024];
 while(true)
 {
    ssize_t amountReceived = recv(socketFD, buffer, 1024, 0);
    if (amountReceived < 0)
        perror("recv failed\n");
    else if(amountReceived > 0)
      {
       buffer[amountReceived] = 0;
       printf("%s\n",buffer);
      }
    else
        break;
  }
  close(socketFD);
}

//This function activates the above function on a new thread
void startListeningAndPrintMessagesOnNewThread(int socketFD)
{
 pthread_t id;
 pthread_create(&id, NULL, (void*)listenAndPrint, (void*)(intptr_t)socketFD);
}

//The client sends messages on one thread and receives broadcasted messages back on a different thread
void main()
{
 int result;
 int socketFD = createTCPIpv4Socket(); 
 struct sockaddr_in *address = createIPv4Address("127.0.0.1",port);
 //struct sockaddr_in *address = createIPv4Address("103.174.70.38",port);
if ((result = connect(socketFD,(struct sockaddr *)address, sizeof(*address)))<0) {
        perror("Connection failed");
        printf("Error code: %d\n", errno);
        exit(EXIT_FAILURE);
    }
 if (result == 0)
    printf("You are connected\n");


char *name = NULL;
size_t nameSize = 0;
printf("please enter your name?\n");
ssize_t nameCount = getline(&name, &nameSize, stdin);
name[nameCount-1] = 0;


char *line = NULL;
size_t lineSize = 0;
printf("type and we will send(type exit)...\n");

startListeningAndPrintMessagesOnNewThread(socketFD);
char buffer[1024];

while(true)
{
 ssize_t charCount = getline(&line, &lineSize, stdin);  //stores the no. of character read from a stream
 line[charCount-1] = 0;
 sprintf(buffer,"%s:%s",name,line);

 if (charCount > 0)  // charCount will be -1 if nothing is received 
 {
  if (strcmp(line,"exit") == 0)  //
      break;
  ssize_t amountWasSent = send(socketFD, buffer, strlen(buffer), 0);
 }
}
free(address);
}


