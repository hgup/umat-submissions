// Saiprasanna G 211203
// This is the MAIN file for the Sorting Comparison Tool 

#include "sortheaderfinal.h"

int main() {
    long int choice, arrayType;

    FILE *fp = fopen("results.txt","w+");
    if (fp == NULL) 
        {   printf("Error opening file!\n");
            return 1;
        }

    printf("Sorting Algorithm Comparison Tool\n");
    fprintf(fp,"Sorting Algorithm Comparison Tool\n");

    while (1) 
    {
        printf("\n1. Randomly Generated Array\n");
        printf("2. Partially Sorted Array (80%%)\n");
        printf("3. Reverse Sorted Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%ld", &choice);

        if (choice == 4) {
            break;
        }

        long int arr[LARGE_SIZE]; // Allocate maximum size for flexibility
        double timeTaken[7][7];     // Array to store times for each sorting algorithm

        switch (choice) {
            case 1:
                arrayType = 1;
                break;
            case 2:
                arrayType = 2;
                break;
            case 3:
                arrayType = 3;
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }

        // Print table header
        printf("\n            Array Sizes\n"); fprintf(fp,"\n            Array Sizes\n");
        printf("Algorithms  "); fprintf(fp,"Algorithms  ");
        for (long int size = SMALL_SIZE; size <= 100000; size *= 10) {
            printf("%10ld", size);
            fprintf(fp,"%10ld", size);
        }
        printf("\n");
        int k=-1;
        // Iterate through the three array sizes
        for (long int size = SMALL_SIZE; size <= 100000; size *= 10) {
            
            k+=1;
            // Generate the array based on the selected type
            switch (arrayType) {
                case 1:
                    generateRandomArray(arr, size);
                    break;
                case 2:
                    generatePartiallySortedArray(arr, size, 80);
                    break;
                case 3:
                    generateReverseSortedArray(arr, size);
                    break;
            }

            // Measure time for each sorting algorithm and store in timeTaken array
            
            timeTaken[k][0] = measureTime(bubbleSort, arr, size);
            timeTaken[k][1] = measureTime(selectionSort, arr, size);
            timeTaken[k][2] = measureTime(insertionSort, arr, size);
            timeTaken[k][3] = measureTime(shellSort, arr, size);

            //timeTaken[4] = measureTime(mergeSort, arr, 0, size - 1);
            long int dup_arr1[LARGE_SIZE];
            assignArray(arr,dup_arr1, LARGE_SIZE);
            clock_t start_5 = clock();
            mergeSort(dup_arr1,0, size-1);
            clock_t end_5 = clock();
            double TimeTaken =  (double)(end_5 - start_5) / CLOCKS_PER_SEC;
            timeTaken[k][4] = TimeTaken;

            timeTaken[k][5] = measureTime(heapSort, arr, size);
            
            //timeTaken[6] = measureTime(quickSort, arr, 0, size - 1);
            long int dup_arr2[LARGE_SIZE];
            assignArray(arr,dup_arr2, LARGE_SIZE);            clock_t start_7 = clock();
            //quickSort(dup_arr2,0, size-1);
            qsort(dup_arr2, size, sizeof(long int), ( int (*)(const void*, const void*))cmpfunc);
            clock_t end_7 = clock();
            TimeTaken =  (double)(end_7 - start_7) / CLOCKS_PER_SEC;
            timeTaken[k][6] = TimeTaken;

        }
        char names[][100] = {"Bubble Sort","Select Sort","Insert Sort","Shell Sort","Merge Sort","Heap Sort","Quick Sort"};

        for (int i=0;i<7;i++)
        {   printf("\n%s",names[i]);
            fprintf(fp,"\n%s",names[i]);
            for (int j=0;j<4;j++)
            {   printf("\t%10.6lf",timeTaken[j][i]);
                fprintf(fp,"\t%10.6lf",timeTaken[j][i]);

            }
            
        }
        
        printf("\nArray Type: %ld (", arrayType); fprintf(fp,"\nArray Type: %ld (", arrayType);
        if (arrayType == 1) {
            printf("Randomly Generated)\n");fprintf(fp,"Randomly Generated)\n");
        } else if (arrayType == 2) {
            printf("Partially Sorted (80%%))\n");fprintf(fp,"Partially Sorted (80%%))\n");
        } else {
            printf("Reverse Sorted)\n");fprintf(fp,"Reverse Sorted)\n");
        }
    }

    printf("\nThank you for using the Sorting Algorithm Comparison tool:)\n");
    fclose(fp);
    printf("\nResults written to 'results.txt' file.\n");

    return 0;
}
