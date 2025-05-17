// Saiprasanna G 211203
// This is the Header file for the Sorting Comparison Tool 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "sortfuncsfinal.c"


// Define array sizes (flexible and modifiable)
#define SMALL_SIZE 100
#define MEDIUM_SIZE 1000
#define LARGE_SIZE 100000

// Function declarations for sorting algorithms 
void printArray(long int arr[], long int size);
void bubbleSort(long int arr[], long int n);
void selectionSort(long int arr[], long int n);
void insertionSort(long int arr[], long int n);
void shellSort(long int arr[], long int n);
void merge(long int arr[], long int left, long int mid, long int right);
void mergeSort(long int arr[], long int left, long int right);
void heapify(long int arr[], long int n, long int i); 
void heapSort(long int arr[], long int n);
long int medianOfThree(long int arr[], long int low, long int high);
long int partition(long int arr[], long int low, long int high);
void quickSort(long int arr[], long int low, long int high);


// Function to copy arrays
void assignArray(long int arr1[], long int arr2[], int size);

// Function to generate a random array
void generateRandomArray(long int arr[], long int n);

// Comparison function for qsort 
int cmpfunc(const void *a, const void *b);

// Function to create a partially sorted array (e.g., 80% sorted)
void generatePartiallySortedArray(long int arr[], long int n, long int sortRatio);

// Function to create a reverse sorted array
void generateReverseSortedArray(long int arr[], long int n);

// Function that returns the time taken by a sorting algorithm
double measureTime(void (*sortFunction)(long int[], long int), long int arr[], long int n);

