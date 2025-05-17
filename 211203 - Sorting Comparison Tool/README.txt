There are 3 files in this folder : 
1. Makefile
2. sortmainfinal.c - MAIN file
3. sortheaderfinal.h - HEADER file
4. sortfuncsfinal.c - function definitions

This is a Sorting Algorithm Comparison tool implemented in C 
	to compare the efficiency of 7 sorting Algorithms: 
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Shell Sort
5. Merge Sort
6. Heap Sort
7. Quick Sort

This tool allows the user to test these algorithms on 3 types of arrays: 
1. Randomly Generated Array
2. Partially Sorted Array (80%)
3. Reverse Sorted Array 

The Results of the comparison will be displayed on the output screen and 
	will also be written into a 'results.txt' file


NOTE - 
* The results.txt is opened in w+ mode - so it will refresh with every re-run of the make file
* The output on the screen is written into the results.txt file and will be written
	into only when the program ends normally (4.Exit option)
