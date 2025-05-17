all: client server
	make client
	make server
client: sock_util.o client.o 
	gcc sock_util.o  client.o -o cliout
server: sock_util.o server1.o
	gcc sock_util.o server1.o -o serout
sock_util.o: sock_util.c
	gcc -c sock_util.c
function.o: function.c
	gcc -c function.c
client.o: client.c
	gcc -c client.c
server1.o: server1.c
	gcc -c server1.c
clean:
	rm main.o function.o                                  


