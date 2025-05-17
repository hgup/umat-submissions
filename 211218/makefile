all: main

main: main.o function.o
	gcc -o main main.o function.o

main.o: main.c
	gcc -c main.c

function.o: function.c
	gcc -c function.c

clean:
	rm -f *.o main

