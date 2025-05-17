test: functions.o board.o
	gcc functions.o board.o
functions.o: functions.c
	gcc -c functions.c
board.o: board.c
	gcc -c board.c
clean:
	rm functions.o main.o
