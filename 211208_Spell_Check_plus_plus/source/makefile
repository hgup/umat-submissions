run : function.o main.o
	gcc function.o main.o
function.o : function.c
	gcc function.c -c
main.o : main.c
	gcc main.c -c
clear : 
	rm function.o main.o