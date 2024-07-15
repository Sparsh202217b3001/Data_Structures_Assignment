#include <stdio.h>

void insertion_sort(int a[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;

        // Move elements of a[0..i-1], that are greater than temp, to one position ahead of their current position
        while (j >= 0 && temp < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[100]; // Assuming maximum size of array is 100
    int n;

    // Prompt user to enter the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Prompt user to enter the elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Sort the array using Insertion Sort
    insertion_sort(a, n);

    // Display the sorted array
    printf("Sorted array: ");
    print_array(a, n);

    return 0;
}
