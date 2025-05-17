test: main.o function.o
	gcc -o sudoku main.o function.o
main.o: main.c
	gcc -c main.c
function.o: function.c
	gcc -c function.c
clean:
	rm main.o function.o                                  

