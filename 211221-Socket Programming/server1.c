#include"sock_util.h"
#include<stdbool.h>
#include<pthread.h>
#include<stdint.h>
#include<unistd.h>
#include<string.h>
#define port 2000 
//This packs the features of the accepted socket like socket file descriptor, address, any error that occurred while creating the socket and success or failure value of the acceptance in one unit
struct AcceptedSocket
{
 int acceptedSocketFD;
 struct sockaddr_in address;
 int error;
 bool acceptedSuccessfully;
};

struct AcceptedSocket acceptedSockets[10];                            int acceptedSocketsCount = 0;

//This function accepts the incoming requests from a client and returns the AcceptedSocket struc. related to the client
struct AcceptedSocket* acceptIncomingConnection(int serverSocketFD)
{
 struct sockaddr_in clientAddress;
 int clientAddressSize = sizeof(struct sockaddr_in);
 int clientSocketFD = accept(serverSocketFD, (struct sockaddr*)&clientAddress, &clientAddressSize);

 struct AcceptedSocket* acceptedSocket = malloc(sizeof(struct AcceptedSocket));
 acceptedSocket->address = clientAddress;
 acceptedSocket->acceptedSocketFD = clientSocketFD;
 acceptedSocket->acceptedSuccessfully = clientSocketFD>0;
 
 if(!acceptedSocket->acceptedSuccessfully)
     acceptedSocket->error = clientSocketFD;

 return acceptedSocket;
}

//This function broadcasts the received message by the server to all theclients connected to the server except to the client that sent the message to the server

void sendReceivedMessageToTheOtherClients(char *buffer,int socketFD)
{
 for(int i = 0; i<acceptedSocketsCount ; i++)                          {                                                                      if (acceptedSockets[i].acceptedSocketFD != socketFD)                  {                                                                      send(acceptedSockets[i].acceptedSocketFD, buffer, strlen(buffer), 0);                                                                      }                                                                    }                                                                    }

//This function takes input the socket file descriptor of a client andprints whatever is sent by the client on that thread
void receiveAndPrintIncomingData(int socketFD)
{
 char buffer[1024];
 char* response = NULL;

 while(true)
 {
    ssize_t amountReceived = recv(socketFD, buffer, 1024, 0);
    if (amountReceived < 0)
        perror("recv failed\n");
    else if(amountReceived > 0)
      {
       buffer[amountReceived] = 0;
       printf("%s\n",buffer);
       sendReceivedMessageToTheOtherClients(buffer,socketFD);
      }
    else
        break;
  }
  close(socketFD);
}

//When ever this function is called it creates a connection between the server and the client on a thread different from the main thread
void startAcceptingIncomingConnection(int serverSocketFD)
{
 while(true)
 {
  struct AcceptedSocket* clientSocket = acceptIncomingConnection(serverSocketFD);
  acceptedSockets[acceptedSocketsCount++] = *clientSocket;
  pthread_t thread;
  pthread_create(&thread, NULL, (void*)receiveAndPrintIncomingData, (void*)(intptr_t)clientSocket->acceptedSocketFD);
 }
}

//This function takes input the client's file desciptor and prints whatever the client sends on that thread 
void receiveAndPrintIncomingDataOnSeparateThread(struct AcceptedSocket *pSocket)
{
 pthread_t id;
 pthread_create(&id,NULL,(void *)receiveAndPrintIncomingData,(void*)(intptr_t)pSocket->acceptedSocketFD);
 pthread_detach(id);
}

//The previous function aids this function to perform the mentioned task
void acceptNewConncetionAndReceiveAndPrintItsData(int serverSocketFD)
{
 while(true)
 {
  struct AcceptedSocket* clientSocket = acceptIncomingConnection(serverSocketFD);
  receiveAndPrintIncomingDataOnSeparateThread(clientSocket);
 }
}

//Here the socket fd for server is created and is bound with the port 2000 so that it can listen to clients requests on this port 
void main()
{
 int serverSocketFD = createTCPIpv4Socket();
 struct sockaddr_in *serverAddress = createIPv4Address("",port);
 int result = bind(serverSocketFD,(struct sockaddr*)serverAddress,sizeof(*serverAddress));
 if(result == 0)
    printf("Socket bound successfully\n");
 
 int listenResult =  listen(serverSocketFD,10);//It can accept to the maximum 10 clients

 startAcceptingIncomingConnection(serverSocketFD);
 shutdown(serverSocketFD, SHUT_RDWR); 
}
