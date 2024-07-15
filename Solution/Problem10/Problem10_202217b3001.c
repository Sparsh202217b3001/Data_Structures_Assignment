#include <stdio.h>
#include <stdlib.h>

// Function to merge the subarrays of a[]
void merge(int a[], int beg, int mid, int end) {
    int i, j, k;
    int n1 = mid - beg + 1; // Size of left subarray
    int n2 = end - mid;     // Size of right subarray

    int *LeftArray = (int *)malloc(n1 * sizeof(int)); // Temporary array for left subarray
    int *RightArray = (int *)malloc(n2 * sizeof(int)); // Temporary array for right subarray

    if (LeftArray == NULL || RightArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Copy data to temp arrays
    for (i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];

    i = 0; // Initial index of first sub-array
    j = 0; // Initial index of second sub-array
    k = beg; // Initial index of merged sub-array

    // Merge the temp arrays back into a[]
    while (i < n1 && j < n2) {
        if (LeftArray[i] <= RightArray[j]) {
            a[k] = LeftArray[i];
            i++;
        } else {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of LeftArray[], if any
    while (i < n1) {
        a[k] = LeftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of RightArray[], if any
    while (j < n2) {
        a[k] = RightArray[j];
        j++;
        k++;
    }

    // Free allocated memory
    free(LeftArray);
    free(RightArray);
}

// Function to implement merge sort
void mergeSort(int a[], int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;

        // Recursively sort the first and second halves
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);

        // Merge the sorted halves
        merge(a, beg, mid, end);
    }
}

// Function to print the array
void printArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Main function to drive the code
int main() {
    int *a;
    int n;

    // Prompt user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for the array
    a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Prompt user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Before sorting array elements are - \n");
    printArray(a, n);

    // Perform merge sort
    mergeSort(a, 0, n - 1);

    printf("After sorting array elements are - \n");
    printArray(a, n);

    // Free allocated memory
    free(a);

    return 0;
}
