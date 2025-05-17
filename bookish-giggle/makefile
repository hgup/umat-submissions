test: functions.o main.o
	gcc functions.o main.o
functions.o: functions.c
	gcc -c functions.c
main.o: main.c
	gcc -c main.c
clean:
	rm functions.o main.o
