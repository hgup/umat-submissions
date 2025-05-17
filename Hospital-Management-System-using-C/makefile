hms: 211206_main.o 211206_functions.o
	gcc 211206_main.o 211206_functions.o -o hms

211206_main.o: 211206_main.c
	gcc -c 211206_main.c

211206_functions.o : 211206_functions.c
	gcc -c 211206_functions.c

clean:
	rm *.o hms