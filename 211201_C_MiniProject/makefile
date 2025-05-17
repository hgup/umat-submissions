main: knights_tour_8.o n_queens_8.o bt_main.o
	gcc knights_tour_8.o n_queens_8.o bt_main.o -o backtrack

knights_tour_8.o: knights_tour_8.c 
	gcc -c knights_tour_8.c 

n_queens_8.o: n_queens_8.c 
	gcc -c n_queens_8.c 

bt_main.o: bt_main.c 
	gcc -c bt_main.c 

clean:
	rm* .o
