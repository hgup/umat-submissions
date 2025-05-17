// Saiprasanna G 211203
/* This file contains the functions for all the sorting algorithms in C 
and some additional functions that help with the program
*/
#include "sortheaderfinal.h"

//----------------------------------------------------------------------------------------------------
// Function to print an array
void printArray(long int arr[], long int size)
{
    for (long int i = 0; i < size; i++)
        printf("%ld, ",arr[i]);
}
//----------------------------------------------------------------------------------------------------

void bubbleSort(long int arr[], long int n) {
    // Flag to indicate if a swap occurred during the pass
    long int swapped = 1;
    long int temp;

    // Outer loop to handle number of passes
    for (long int i = 0; i < n - 1 && swapped; i++) 
    {
        swapped = 0;  // Reset flag for current pass

        // Inner loop to compare adjacent elements
        for (long int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                // Swap elements if out of order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;  // Set flag if a swap occurred
            }
        }
        // If no two elements were swapped by inner loop, then break
        //if (swapped == 0)            break;
    }
}

// Time complexity: O(n^2) - Nested loops iterate through all possible pairs
// Space complexity: O(1) - In-place sorting, no extra space needed
//----------------------------------------------------------------------------------------------------

void selectionSort(long int arr[], long int n) {
    long int minIndex, temp;

    // One by one move boundary of unsorted subarray
    for (long int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        minIndex = i;
        for (long int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Time complexity: O(n^2) - Similar to Bubble Sort, nested loops
// Space complexity: O(1) - In-place sorting
//----------------------------------------------------------------------------------------------------

void insertionSort(long int arr[], long int n) 
{
    long int i,j,key;

    // One by one move boundary of unsorted subarray
    for ( i = 1; i < n; i++) 
    {   
        key = arr[i];
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        for (j=i-1; j>=0; j--) 
        {   if (arr[j] > key)
                { arr[j + 1] = arr[j];
                }
            else break;      
        
            
        }
        arr[j + 1] = key;  // Insert the shifted element in its correct position
    }
}

// Time complexity: O(n^2) - In worst case, each element needs shifting
// Space complexity: O(1) - In-place sorting
//----------------------------------------------------------------------------------------------------

void shellSort(long int arr[], long int n) {
    // Start with a large gap, halved in each iteration
    long int i,j,gap;
    for ( gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for current gap size
        for ( i = gap; i < n; i++) {
            // The first element (arr[i]) is already in its correct position
            // compared to the subarray arr[0..i-gap]
            long int key = arr[i];

            // Find the correct position for key using a nested loop
            for ( j = i - gap; j >= 0 && arr[j] > key; j -= gap) 
            {
                arr[j + gap] = arr[j]; // Shift elements by gap positions
            }

            // Insert the shifted element in its correct position
            arr[j + gap] = key;
        }
    }
}


// Time Complexity:
//   - Average: O(n log n)
//   - Worst Case: O(n^2) (occurs for specific gap sequences)
// Space Complexity: O(1) - In-place sorting, no extra space needed


//----------------------------------------------------------------------------------------------------
void merge(long int arr[], long int left, long int mid, long int right) 
{
    long int n1 = mid - left + 1;  // Size of left subarray
    long int n2 = right - mid;     // Size of right subarray

    // Create temporary arrays
    long int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (long int i = 0; i < n1; i++) 
    {
        L[i] = arr[left + i];
    }
    for (long int j = 0; j < n2; j++) 
    {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back long into arr[left..right]
    long int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long int arr[], long int left, long int right) 
{
    if (left < right) 
    {
        // Find the middle polong int of the subarray
        long int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Time Complexity: O(n log n) - Divide and Conquer approach with logarithmic depth
// Space Complexity: O(n) - Extra space needed for temporary arrays during merge operation
//-------------------------------------------------------------------------------------------

void swap(long int *a, long int *b) 
{
    long int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(long int arr[], long int n, long int i) 
{
    long int largest = i;  // Initialize largest as root
    long int left = 2 * i + 1;  // left = 2*i + 1
    long int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) 
    {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) 
    {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(long int arr[], long int n) 
{
    // Build a max heap
    for (long int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (long int i = n - 1; i > 0; i--) 
    {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Time Complexity: O(n log n) - Heap creation and extraction follow divide and conquer approach
// Space Complexity: O(1) - In-place sorting, no extra space needed (except for swap operation)

//----------------------------------------------------------------------------------------------------
// Function to find median of three elements
long int medianOfThree(long int arr[], long int low, long int high) {
    long int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid]) {
        if (arr[mid] > arr[high])
            return mid;
        else if (arr[low] > arr[high])
            return high;
        else
            return low;
    } else {
        if (arr[low] > arr[high])
            return low;
        else if (arr[mid] > arr[high])
            return high;
        else
            return mid;
    }
}

// Function to partition the array and return the partition index
long int partition(long int arr[], long int low, long int high) {
    // Optimized pivot selection using median of three
    long int pivotIndex = medianOfThree(arr, low, high);
    long int pivot = arr[pivotIndex];
    
    // Move pivot to the end
    swap(&arr[pivotIndex], &arr[high]);

    long int i = low - 1; // Index of smaller element

    for (long int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;    // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(long int arr[], long int low, long int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        long int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Time Complexity:
//   - Average: O(n log n) - Efficient for random data
//   - Worst Case: O(n^2) - Can occur for specific pivot choices (already sorted or nearly sorted data)
// Space Complexity: O(log n) - Recursive calls use call stack, can be optimized using tail recursion
//----------------------------------------------------------------------------------------------------

//Function to copy arrays
void assignArray(long int arr1[],long int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        arr2[i] = arr1[i];
    }
}


// Function to generate a random array
void generateRandomArray(long int arr[], long int n) {
    srand(time(NULL)); // Seed random number generator
    for (long int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

// Comparison function for qsort 
int cmpfunc(const void *a, const void *b) {
    return (*(long int*)a - *(long int*)b);
}

// Function to create a partially sorted array (e.g., 80% sorted)
void generatePartiallySortedArray(long int arr[], long int n, long int sortRatio) {
    generateRandomArray(arr, n);
    long int sortedElements = n * sortRatio / 100;
    qsort(arr, sortedElements, sizeof(long int), cmpfunc); // Use quicksort to partially sort
}

// Function to create a reverse sorted array
void generateReverseSortedArray(long int arr[], long int n) {
    for (long int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}


//Function that returns the time taken by a sorting algorithm
double measureTime(void (*sortFunction)(long int[], long int), long int arr[], long int n) {
    long int dup_arr[LARGE_SIZE];
    assignArray(arr,dup_arr, LARGE_SIZE);
    clock_t start = clock();
    sortFunction(dup_arr, n);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}